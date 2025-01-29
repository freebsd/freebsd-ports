--- src/geo/GeomMeshMatcher.cpp.orig	2024-03-29 22:07:00 UTC
+++ src/geo/GeomMeshMatcher.cpp
@@ -12,7 +12,6 @@
 #include <list>
 #include <vector>
 #include "GeomMeshMatcher.h"
-#include "Pair.h"
 #include "discreteVertex.h"
 #include "GmshMessage.h"
 #include "SOrientedBoundingBox.h"
@@ -61,22 +60,22 @@ void getIntersection(std::vector<T> &res, std::vector<
   }
 }
 
-template <class T> T findMatching(std::vector<Pair<T, T> > &matching, T &entity)
+template <class T> T findMatching(std::vector<std::pair<T, T> > &matching, T &entity)
 {
   for(auto pair = matching.begin(); pair != matching.end(); pair++) {
-    if((*pair).left() == entity) return ((*pair).right());
+    if((*pair).first == entity) return ((*pair).second);
   }
   return (0);
 }
 
 // Matching vertices
 
-std::vector<Pair<GVertex *, GVertex *> > *
+std::vector<std::pair<GVertex *, GVertex *> > *
 GeomMeshMatcher::matchVertices(GModel *m1, GModel *m2, bool &ok)
 {
   // Vector that will be returned.
-  std::vector<Pair<GVertex *, GVertex *> > *coresp_v =
-    new std::vector<Pair<GVertex *, GVertex *> >;
+  std::vector<std::pair<GVertex *, GVertex *> > *coresp_v =
+    new std::vector<std::pair<GVertex *, GVertex *> >;
   int num_matched_vertices = 0;
   int num_total_vertices = m2->getNumVertices();
 
@@ -107,7 +106,7 @@ GeomMeshMatcher::matchVertices(GModel *m1, GModel *m2,
 
     if(choice && best_score != DBL_MAX) {
       choice->physicals = v1->physicals;
-      coresp_v->push_back(Pair<GVertex *, GVertex *>(v1, choice));
+      coresp_v->push_back(std::make_pair(v1, choice));
       num_matched_vertices++;
     }
   }
@@ -120,17 +119,17 @@ GeomMeshMatcher::matchVertices(GModel *m1, GModel *m2,
 
 // Matching edges
 
-std::vector<Pair<GEdge *, GEdge *> > *
+std::vector<std::pair<GEdge *, GEdge *> > *
 GeomMeshMatcher::matchEdges(GModel *m1, GModel *m2,
-                            std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
+                            std::vector<std::pair<GVertex *, GVertex *> > *coresp_v,
                             bool &ok)
 {
   int num_matched_edges = 0;
   int num_total_edges = m2->getNumEdges();
 
   // Vector that will be returned.
-  std::vector<Pair<GEdge *, GEdge *> > *coresp_e =
-    new std::vector<Pair<GEdge *, GEdge *> >;
+  std::vector<std::pair<GEdge *, GEdge *> > *coresp_e =
+    new std::vector<std::pair<GEdge *, GEdge *> >;
 
   std::vector<GEdge *> closed_curves;
 
@@ -195,7 +194,7 @@ GeomMeshMatcher::matchEdges(GModel *m1, GModel *m2,
         }
       }
     }
-    coresp_e->push_back(Pair<GEdge *, GEdge *>(e1, choice));
+    coresp_e->push_back(std::make_pair(e1, choice));
 
     // copy topological information
     if(choice) {
@@ -213,16 +212,16 @@ GeomMeshMatcher::matchEdges(GModel *m1, GModel *m2,
 
 // Matching faces
 
-std::vector<Pair<GFace *, GFace *> > *
+std::vector<std::pair<GFace *, GFace *> > *
 GeomMeshMatcher::matchFaces(GModel *m1, GModel *m2,
-                            std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
+                            std::vector<std::pair<GEdge *, GEdge *> > *coresp_e,
                             bool &ok)
 {
   int num_matched_faces = 0;
   int num_total_faces = m2->getNumFaces();
 
-  std::vector<Pair<GFace *, GFace *> > *coresp_f =
-    new std::vector<Pair<GFace *, GFace *> >;
+  std::vector<std::pair<GFace *, GFace *> > *coresp_f =
+    new std::vector<std::pair<GFace *, GFace *> >;
 
   for(auto fit = m1->firstFace(); fit != m1->lastFace(); fit++) {
     GFace *f1 = (GFace *)*fit;
@@ -276,7 +275,7 @@ GeomMeshMatcher::matchFaces(GModel *m1, GModel *m2,
 
     if(choice) {
       Msg::Debug("Surfaces %i and %i match", f1->tag(), choice->tag());
-      coresp_f->push_back(Pair<GFace *, GFace *>(f1, choice));
+      coresp_f->push_back(std::make_pair(f1, choice));
       // copy topological information
       choice->setTag(f1->tag());
       f1->physicals = choice->physicals;
@@ -292,17 +291,17 @@ GeomMeshMatcher::matchFaces(GModel *m1, GModel *m2,
 
 // Matching regions
 
-std::vector<Pair<GRegion *, GRegion *> > *
+std::vector<std::pair<GRegion *, GRegion *> > *
 GeomMeshMatcher::matchRegions(GModel *m1, GModel *m2,
-                              std::vector<Pair<GFace *, GFace *> > *coresp_f,
+                              std::vector<std::pair<GFace *, GFace *> > *coresp_f,
                               bool &ok)
 
 {
   int num_matched_regions = 0;
   int num_total_regions = 0;
 
-  std::vector<Pair<GRegion *, GRegion *> > *coresp_r =
-    new std::vector<Pair<GRegion *, GRegion *> >;
+  std::vector<std::pair<GRegion *, GRegion *> > *coresp_r =
+    new std::vector<std::pair<GRegion *, GRegion *> >;
 
   std::vector<GEntity *> m1_entities;
   m1->getEntities(m1_entities, 3);
@@ -344,8 +343,7 @@ GeomMeshMatcher::matchRegions(GModel *m1, GModel *m2,
     }
 
     if(common_regions.size() == 1) {
-      coresp_r->push_back(
-        Pair<GRegion *, GRegion *>((GRegion *)*entity1, common_regions[0]));
+      coresp_r->push_back(std::make_pair((GRegion *)*entity1, common_regions[0]));
       common_regions[0]->setTag(((GRegion *)*entity1)->tag());
       (*entity1)->physicals = common_regions[0]->physicals;
       num_matched_regions++;
@@ -377,8 +375,7 @@ GeomMeshMatcher::matchRegions(GModel *m1, GModel *m2,
           choice = (*candidate);
         }
       }
-      coresp_r->push_back(
-        Pair<GRegion *, GRegion *>((GRegion *)*entity1, choice));
+      coresp_r->push_back(std::make_pair((GRegion *)*entity1, choice));
       if(choice) {
         choice->setTag(((GRegion *)*entity1)->tag());
         (*entity1)->physicals = choice->physicals;
@@ -594,13 +591,13 @@ template <class GEType>
 }
 
 template <class GEType>
-static void copy_periodicity(std::vector<Pair<GEType *, GEType *> > &eCor,
+static void copy_periodicity(std::vector<std::pair<GEType *, GEType *> > &eCor,
                              std::map<MVertex *, MVertex *> &mesh_to_geom)
 {
   typename std::multimap<GEType *, GEType *> eMap; // (eCor.begin(),eCor.end());
   auto eIter = eCor.begin();
   for(; eIter != eCor.end(); ++eIter) {
-    eMap.insert(std::make_pair(eIter->second(), eIter->first()));
+    eMap.insert(std::make_pair(eIter->second, eIter->first));
   }
 
   auto srcIter = eMap.begin();
@@ -651,12 +648,12 @@ template <class GEType>
 }
 
 template <class GEType>
-static bool apply_periodicity(std::vector<Pair<GEType *, GEType *> > &eCor)
+static bool apply_periodicity(std::vector<std::pair<GEType *, GEType *> > &eCor)
 {
   typename std::multimap<GEType *, GEType *> eMap; // (eCor.begin(),eCor.end());
   auto eIter = eCor.begin();
   for(; eIter != eCor.end(); ++eIter) {
-    eMap.insert(std::make_pair(eIter->second(), eIter->first()));
+    eMap.insert(std::make_pair(eIter->second, eIter->first));
   }
 
   auto srcIter = eMap.begin();
@@ -787,57 +784,57 @@ void copy_vertices(GModel *geom, GModel *mesh,
 
 void copy_vertices(GModel *geom, GModel *mesh,
                    std::map<MVertex *, MVertex *> &_mesh_to_geom,
-                   std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
-                   std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
-                   std::vector<Pair<GFace *, GFace *> > *coresp_f,
-                   std::vector<Pair<GRegion *, GRegion *> > *coresp_r)
+                   std::vector<std::pair<GVertex *, GVertex *> > *coresp_v,
+                   std::vector<std::pair<GEdge *, GEdge *> > *coresp_e,
+                   std::vector<std::pair<GFace *, GFace *> > *coresp_f,
+                   std::vector<std::pair<GRegion *, GRegion *> > *coresp_r)
 {
   // copy all elements
   for(std::size_t i = 0; i < coresp_v->size(); ++i)
-    copy_vertices((*coresp_v)[i].first(), (*coresp_v)[i].second(),
+    copy_vertices((*coresp_v)[i].first, (*coresp_v)[i].second,
                   _mesh_to_geom);
   for(std::size_t i = 0; i < coresp_e->size(); ++i)
-    copy_vertices((*coresp_e)[i].first(), (*coresp_e)[i].second(),
+    copy_vertices((*coresp_e)[i].first, (*coresp_e)[i].second,
                   _mesh_to_geom);
   for(std::size_t i = 0; i < coresp_f->size(); ++i)
-    copy_vertices((*coresp_f)[i].first(), (*coresp_f)[i].second(),
+    copy_vertices((*coresp_f)[i].first, (*coresp_f)[i].second,
                   _mesh_to_geom);
   for(std::size_t i = 0; i < coresp_r->size(); ++i)
-    copy_vertices((*coresp_r)[i].first(), (*coresp_r)[i].second(),
+    copy_vertices((*coresp_r)[i].first, (*coresp_r)[i].second,
                   _mesh_to_geom);
 }
 void copy_elements(GModel *geom, GModel *mesh,
                    std::map<MVertex *, MVertex *> &_mesh_to_geom,
-                   std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
-                   std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
-                   std::vector<Pair<GFace *, GFace *> > *coresp_f,
-                   std::vector<Pair<GRegion *, GRegion *> > *coresp_r)
+                   std::vector<std::pair<GVertex *, GVertex *> > *coresp_v,
+                   std::vector<std::pair<GEdge *, GEdge *> > *coresp_e,
+                   std::vector<std::pair<GFace *, GFace *> > *coresp_f,
+                   std::vector<std::pair<GRegion *, GRegion *> > *coresp_r)
 {
   // copy all elements
 
   for(std::size_t i = 0; i < coresp_v->size(); ++i) {
-    GVertex *dest = (*coresp_v)[i].first();
-    GVertex *orig = (*coresp_v)[i].second();
+    GVertex *dest = (*coresp_v)[i].first;
+    GVertex *orig = (*coresp_v)[i].second;
     copy_elements<MPoint>(dest->points, orig->points, _mesh_to_geom);
   }
 
   for(std::size_t i = 0; i < coresp_e->size(); ++i) {
-    GEdge *dest = (*coresp_e)[i].first();
-    GEdge *orig = (*coresp_e)[i].second();
+    GEdge *dest = (*coresp_e)[i].first;
+    GEdge *orig = (*coresp_e)[i].second;
     copy_elements<MLine>(dest->lines, orig->lines, _mesh_to_geom);
   }
 
   for(std::size_t i = 0; i < coresp_f->size(); ++i) {
-    GFace *dest = (*coresp_f)[i].first();
-    GFace *orig = (*coresp_f)[i].second();
+    GFace *dest = (*coresp_f)[i].first;
+    GFace *orig = (*coresp_f)[i].second;
     copy_elements<MTriangle>(dest->triangles, orig->triangles, _mesh_to_geom);
     copy_elements<MQuadrangle>(dest->quadrangles, orig->quadrangles,
                                _mesh_to_geom);
   }
 
   for(std::size_t i = 0; i < coresp_r->size(); ++i) {
-    GRegion *dest = (*coresp_r)[i].first();
-    GRegion *orig = (*coresp_r)[i].second();
+    GRegion *dest = (*coresp_r)[i].first;
+    GRegion *orig = (*coresp_r)[i].second;
     copy_elements<MTetrahedron>(dest->tetrahedra, orig->tetrahedra,
                                 _mesh_to_geom);
     copy_elements<MHexahedron>(dest->hexahedra, orig->hexahedra, _mesh_to_geom);
@@ -857,10 +854,10 @@ int GeomMeshMatcher::match(GModel *geom, GModel *mesh)
 
   bool ok = true;
 
-  std::vector<Pair<GVertex *, GVertex *> > *coresp_v(nullptr);
-  std::vector<Pair<GEdge *, GEdge *> > *coresp_e(nullptr);
-  std::vector<Pair<GFace *, GFace *> > *coresp_f(nullptr);
-  std::vector<Pair<GRegion *, GRegion *> > *coresp_r(nullptr);
+  std::vector<std::pair<GVertex *, GVertex *> > *coresp_v(nullptr);
+  std::vector<std::pair<GEdge *, GEdge *> > *coresp_e(nullptr);
+  std::vector<std::pair<GFace *, GFace *> > *coresp_f(nullptr);
+  std::vector<std::pair<GRegion *, GRegion *> > *coresp_r(nullptr);
 
   coresp_v = matchVertices(geom, mesh, ok);
   if(ok) {
