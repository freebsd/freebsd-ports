--- ./src/gfx/generic/generic_stretch_blit.c.orig	2011-06-18 23:08:07.000000000 +0200
+++ ./src/gfx/generic/generic_stretch_blit.c	2011-06-18 23:08:13.000000000 +0200
@@ -72,6 +72,8 @@
 
 #if DFB_SMOOTH_SCALING
 
+typedef unsigned long ulong;
+
 typedef struct {
      DFBRegion   clip;
      const void *colors;
