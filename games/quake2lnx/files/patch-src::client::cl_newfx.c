--- src/client/cl_newfx.c.orig	Thu Jun 12 14:36:30 2003
+++ src/client/cl_newfx.c	Thu Jun 12 14:58:25 2003
@@ -143,7 +143,9 @@
 	vec3_t		vec;
 	float		len;
 //	int			j;
+#ifndef QMAX
 	cparticle_t	*p;
+#endif
 	float		dec;
 	vec3_t		right, up;
 //	int			i;
@@ -266,11 +268,12 @@
 	vec3_t		vec;
 #ifdef QMAX
 	vec3_t color = { color8red(color8), color8green(color8), color8blue(color8)};
+#else
+	int			j;
+	cparticle_t	*p;
 #endif
 
 	float		len;
-	int			j;
-	cparticle_t	*p;
 
 	VectorCopy (start, move);
 	VectorSubtract (end, start, vec);
@@ -448,8 +451,11 @@
 	vec3_t		move;
 	vec3_t		vec;
 	float		len;
-	int			i, j;
+	int			i;
+#ifndef QMAX
+	int		j;
 	cparticle_t	*p;
+#endif
 	float		dec;
 
 	VectorCopy (start, move);
@@ -1062,7 +1068,9 @@
 	vec3_t			dir;
 	int				i;
 	cparticle_t		*p;
+#ifndef QMAX
 	static int colortable[4] = {2*8,13*8,21*8,18*8};
+#endif
 	float			ratio;
 
 	ratio = 1.0 - (((float)self->endtime - (float)cl.time)/2100.0);
@@ -1099,7 +1107,9 @@
 	vec3_t			dir;
 	int				i;
 	cparticle_t		*p;
+#ifndef QMAX
 	static int colortable[4] = {110, 112, 114, 116};
+#endif
 	float			ratio;
 
 	ratio = 1.0 - (((float)self->endtime - (float)cl.time)/1000.0);
@@ -1133,7 +1143,9 @@
 
 void CL_WidowSplash (vec3_t org)
 {
+#ifndef QMAX
 	static int colortable[4] = {2*8,13*8,21*8,18*8};
+#endif
 	int			i;
 	cparticle_t	*p;
 	vec3_t		dir;
@@ -1260,10 +1272,12 @@
 */
 void CL_ColorExplosionParticles (vec3_t org, int color8, int run)
 {
-	int			i, j;
-	cparticle_t	*p;
+	int			i;
 #ifdef QMAX
 	vec3_t color = { color8red(color8), color8green(color8), color8blue(color8)};
+#else
+	int		j;
+	cparticle_t	*p;
 #endif
 	for (i=0 ; i<128 ; i++)
 	{
