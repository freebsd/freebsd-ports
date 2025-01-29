--- src/common/gmsh.cpp.orig	2024-05-05 07:36:23 UTC
+++ src/common/gmsh.cpp
@@ -443,7 +443,7 @@ GMSH_API void gmsh::model::getEntitiesForPhysicalName(
   GModel::current()->getEntitiesForPhysicalName(name, entities);
   if(entities.size() != 0) {
     for(auto ge : entities) {
-      dimTags.push_back(std::pair<int, int >(ge->dim(), ge->tag()));
+      dimTags.push_back(std::make_pair(ge->dim(), ge->tag()));
     }
   }
   else {
@@ -847,13 +847,13 @@ gmsh::model::getDerivative(const int dim, const int ta
     GFace *gf = static_cast<GFace *>(entity);
     for(std::size_t i = 0; i < parametricCoord.size(); i += 2) {
       SPoint2 param(parametricCoord[i], parametricCoord[i + 1]);
-      Pair<SVector3, SVector3> d = gf->firstDer(param);
-      deriv.push_back(d.left().x());
-      deriv.push_back(d.left().y());
-      deriv.push_back(d.left().z());
-      deriv.push_back(d.right().x());
-      deriv.push_back(d.right().y());
-      deriv.push_back(d.right().z());
+      std::pair<SVector3, SVector3> d = gf->firstDer(param);
+      deriv.push_back(d.first.x());
+      deriv.push_back(d.first.y());
+      deriv.push_back(d.first.z());
+      deriv.push_back(d.second.x());
+      deriv.push_back(d.second.y());
+      deriv.push_back(d.second.z());
     }
   }
 }
