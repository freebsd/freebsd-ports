--- common/bspfile.h.orig	2016-03-30 06:24:01 UTC
+++ common/bspfile.h
@@ -155,7 +155,7 @@ dvertex_t;
 
 typedef struct
 {
-    float           normal[3];
+    vec3_t          normal;
     float           dist;
     planetypes      type;                                  // PLANE_X - PLANE_ANYZ ?remove? trivial to regenerate
 }
