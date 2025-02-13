//
// Created by Jhwangbo on 05.10.17.
//

#ifndef RAISIM_RAICOLLISIONMESH_HPP
#define RAISIM_RAICOLLISIONMESH_HPP

#include "SingleBodyObject.hpp"

namespace raisim {

class Mesh : public SingleBodyObject {

 public:

  explicit Mesh(const std::string &filename, dSpaceID space, double mass, const Mat<3, 3> &inertia, const Vec<3> &COM);
  explicit Mesh(const std::vector<float> &verticies,
                const std::vector<unsigned int> &idx,
                dSpaceID space,
                double mass,
                const Mat<3, 3> &inertia,
                const Vec<3> &COM);

  ~Mesh();

  // return mesh file name if it was created with a file. Otherwise, returns an empty string
  const std::string& getMeshFileName() { return meshFileName_; }

  const std::vector<float>& getVerticies() { return verticies_; }

  const std::vector<unsigned int>& getIndicies() { return idx_; }

  static void loadObj(const std::string &filename, std::vector<float>& verticies, std::vector<dTriIndex>& idx);

 protected:

  void _init(dSpaceID space,
             double mass,
             const Mat<3, 3> &inertia,
             const Vec<3> &COM);

  std::vector<unsigned int> idx_;
  std::vector<float> verticies_;
  dTriMeshDataID Data_;
  std::string meshFileName_;

};

} // raisim

#endif //RAISIM_RAICOLLISIONSPHERE_HPP
