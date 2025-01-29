--- src/geo/GeomMeshMatcher.h.orig	2024-03-29 22:07:00 UTC
+++ src/geo/GeomMeshMatcher.h
@@ -16,21 +16,20 @@
 #include "GEdge.h"
 #include "GFace.h"
 #include "GRegion.h"
-#include "Pair.h"
 
 class GeomMeshMatcher {
 private:
-  std::vector<Pair<GVertex *, GVertex *> > *matchVertices(GModel *m1,
-                                                          GModel *m2, bool &ok);
-  std::vector<Pair<GEdge *, GEdge *> > *
+  std::vector<std::pair<GVertex *, GVertex *> > *
+  matchVertices(GModel *m1, GModel *m2, bool &ok);
+  std::vector<std::pair<GEdge *, GEdge *> > *
   matchEdges(GModel *m1, GModel *m2,
-             std::vector<Pair<GVertex *, GVertex *> > *coresp_v, bool &ok);
-  std::vector<Pair<GFace *, GFace *> > *
+             std::vector<std::pair<GVertex *, GVertex *> > *coresp_v, bool &ok);
+  std::vector<std::pair<GFace *, GFace *> > *
   matchFaces(GModel *m1, GModel *m2,
-             std::vector<Pair<GEdge *, GEdge *> > *coresp_e, bool &ok);
-  std::vector<Pair<GRegion *, GRegion *> > *
+             std::vector<std::pair<GEdge *, GEdge *> > *coresp_e, bool &ok);
+  std::vector<std::pair<GRegion *, GRegion *> > *
   matchRegions(GModel *m1, GModel *m2,
-               std::vector<Pair<GFace *, GFace *> > *coresp_f, bool &ok);
+               std::vector<std::pair<GFace *, GFace *> > *coresp_f, bool &ok);
   static GeomMeshMatcher *_gmm_instance;
   GeomMeshMatcher() {}
   ~GeomMeshMatcher() {}
