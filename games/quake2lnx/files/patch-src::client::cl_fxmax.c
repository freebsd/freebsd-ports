--- src/client/cl_fxmax.c.orig	Thu Jun 12 14:32:17 2003
+++ src/client/cl_fxmax.c	Thu Jun 12 14:34:33 2003
@@ -1733,7 +1733,6 @@
 
 void CL_Disruptor_Explosion_Particle (vec3_t org, float size)
 {
-	int i;
 	float	alphastart = 1,
 			alphadecel = -5;
 	cparticle_t *p;
@@ -1817,7 +1816,7 @@
 {
 	float length;
 	int i;
-	vec3_t len, ang;
+	vec3_t len;
 
 	VectorSubtract(p->angle, org, len);
 	{
@@ -2194,7 +2193,6 @@
 
 void pSparksThink (cparticle_t *p, vec3_t org, vec3_t angle, float *alpha, float *size, int *image, float *time)
 {
-	vec3_t dir;
 	int i;
 
 	//setting up angle for sparks
@@ -2523,7 +2521,6 @@
 #define pBlasterMaxSize 5
 void pBlasterThink (cparticle_t *p, vec3_t org, vec3_t angle, float *alpha, float *size, int *image, float *time)
 {
-	int i;
 	vec3_t len;
 	VectorSubtract(p->angle, org, len);
 	
@@ -3038,7 +3035,6 @@
 	vec3_t		vec, point;
 	int			i;
 	float		len;
-	float		dec;
 	vec3_t		right, up;
 	qboolean	colored = (cl_railtype->value!=1);
 
