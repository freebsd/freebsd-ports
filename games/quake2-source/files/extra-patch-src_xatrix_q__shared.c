--- src/xatrix/q_shared.c.orig	Mon Nov 30 17:55:36 1998
+++ src/xatrix/q_shared.c	Tue Sep 27 20:04:53 2005
@@ -326,7 +326,7 @@
 Returns 1, 2, or 1 + 2
 ==================
 */
-#if !id386 || defined __linux__ 
+#if !id386 || defined __linux__ || defined __FreeBSD__
 int BoxOnPlaneSide (vec3_t emins, vec3_t emaxs, struct cplane_s *p)
 {
 	float	dist1, dist2;
