--- ./q_shared.c.orig	Sat Dec 30 19:09:03 2006
+++ ./q_shared.c	Sat Dec 30 19:09:23 2006
@@ -326,12 +326,12 @@
 Returns 1, 2, or 1 + 2
 ==================
 */
-#if !id386
+#if !id386 || defined __unix__ || defined __sun__
 int BoxOnPlaneSide (vec3_t emins, vec3_t emaxs, struct cplane_s *p)
 {
 	float	dist1, dist2;
 	int		sides;
-
+	
 // fast axial cases
 	if (p->type < 3)
 	{
