--- snd_dma.c.orig	2007-11-14 23:38:25.000000000 +0600
+++ snd_dma.c	2007-11-14 23:41:15.000000000 +0600
@@ -49,11 +49,11 @@
 volatile dma_t *shm = 0;
 volatile dma_t sn;
 
-static vec3_t	listener_origin;
-static vec3_t	listener_forward;
-static vec3_t	listener_right;
-static vec3_t	listener_up;
-static vec_t	sound_nominal_clip_dist = 1000.0;
+vec3_t	listener_origin;
+vec3_t	listener_forward;
+vec3_t	listener_right;
+vec3_t	listener_up;
+vec_t	sound_nominal_clip_dist = 1000.0;
 
 static int	soundtime;		// sample PAIRS
 int   		paintedtime; 	// sample PAIRS
