--- r_part.c.orig	Wed Jan  7 00:39:44 2004
+++ r_part.c	Sun Jan 22 22:07:23 2006
@@ -58,7 +58,7 @@
 
 vec3_t				r_pright, r_pup, r_ppn;
 
-#if	!id386
+#if !defined(id386) && !defined(GLQUAKE)
 
 void D_DrawParticle (particle_t *pparticle) {
 	vec3_t local, transformed;
