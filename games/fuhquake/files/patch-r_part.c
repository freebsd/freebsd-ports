--- r_part.c.orig	Wed Feb  4 23:15:44 2004
+++ r_part.c	Wed Feb  4 23:32:01 2004
@@ -60,6 +60,17 @@
 
 #if	!id386
 
+#define	PARTICLE_Z_CLIP		8.0
+float	xcenter, ycenter;
+int	d_vrectx, d_vrecty, d_vrectright_particle, d_vrectbottom_particle;
+short	*d_pzbuffer;
+unsigned int	d_zwidth;
+pixel_t	*d_viewbuffer;
+#define	MAXHEIGHT	1024
+int	d_scantable[MAXHEIGHT];
+int	d_y_aspect_shift, d_pix_min, d_pix_max, d_pix_shift;
+int	screenwidth;
+
 void D_DrawParticle (particle_t *pparticle) {
 	vec3_t local, transformed;
 	float zi;
