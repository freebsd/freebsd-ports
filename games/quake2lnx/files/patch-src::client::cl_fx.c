--- src/client/cl_fx.c.orig	Thu Jun 12 14:24:20 2003
+++ src/client/cl_fx.c	Thu Jun 12 14:24:42 2003
@@ -1507,7 +1507,7 @@
 */
 #ifdef QMAX
 void CL_FlagTrail (vec3_t start, vec3_t end, boolean isred)
-#else)
+#else
 void CL_FlagTrail (vec3_t start, vec3_t end, float color)
 #endif
 {
