--- contrib/domhex/BackgroundMesh2D.h.orig	2024-03-29 22:06:54 UTC
+++ contrib/domhex/BackgroundMesh2D.h
@@ -9,9 +9,7 @@
 #include <string>
 #include <map>
 #include <vector>
-#include "Pair.h"
 #include "STensor3.h"
-
 #include "BGMBase.h"
 
 class MTriangle;
@@ -133,8 +131,8 @@ class frameFieldBackgroundMesh2D : public backgroundMe
   void eval_crossfield(MVertex *vert, STensor3 &cf);
 
   void exportCrossField(const std::string &filename);
-  Pair<SVector3, SVector3> compute_crossfield_directions(double u, double v,
-                                                         double angle_current);
+  std::pair<SVector3, SVector3> compute_crossfield_directions(double u, double v,
+                                                              double angle_current);
   bool compute_RK_infos(double u, double v, double x, double y, double z,
                         RK_form &infos);
 
