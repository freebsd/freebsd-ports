--- ./game/q_shared.c.orig	Wed May 17 22:21:33 2006
+++ ./game/q_shared.c	Wed May 17 22:28:01 2006
@@ -421,7 +421,7 @@
 Returns 1, 2, or 1 + 2
 ==================
 */
-#if !id386 || defined __linux__ || defined __FreeBSD__
+#if !id386 || defined __unix__
 int BoxOnPlaneSide (vec3_t emins, vec3_t emaxs, struct cplane_s *p)
 {
 	float	dist1, dist2;
