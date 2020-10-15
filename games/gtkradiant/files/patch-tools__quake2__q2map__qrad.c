--- tools/quake2/q2map/qrad.c.orig	2006-02-10 22:01:20 UTC
+++ tools/quake2/q2map/qrad.c
@@ -44,7 +44,7 @@
 vec3_t		face_offset[MAX_MAP_FACES];		// for rotating bmodels
 dplane_t	backplanes[MAX_MAP_PLANES];
 
-char		inbase[32], outbase[32];
+extern char		inbase[32], outbase[32];
 
 int			fakeplanes;					// created planes for origin offset 
 
@@ -64,11 +64,13 @@
 
 float	lightscale = 1.0;
 
-qboolean	glview;
+extern qboolean	glview;
 
 qboolean	nopvs;
 
-char		source[1024];
+extern char		source[1024];
+
+void (*CalcTextureReflectivity) (void);
 
 float	direct_scale =	0.4;
 float	entity_scale =	1.0;
