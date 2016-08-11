--- src/gfx/generic/generic_stretch_blit.c.orig	2012-05-23 13:43:12 UTC
+++ src/gfx/generic/generic_stretch_blit.c
@@ -72,6 +72,8 @@
 
 #if DFB_SMOOTH_SCALING
 
+typedef unsigned long ulong;
+
 typedef struct {
      DFBRegion   clip;
      const void *colors;
