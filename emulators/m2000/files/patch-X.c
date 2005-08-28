--- X.c.orig	Wed Aug 24 15:59:59 2005
+++ X.c	Wed Aug 24 16:00:08 2005
@@ -290,7 +290,7 @@
  DefaultGC=DefaultGCOfScreen (Scr);
  DefaultCMap=DefaultColormapOfScreen (Scr);
  bpp=DefaultDepthOfScreen (Scr);
- if (bpp!=8 && bpp!=16 && bpp!=32)
+ if (bpp!=8 && bpp!=16 && bpp!=24 && bpp!=32)
  {
   printf ("FAILED - Only 8,16 and 32 bpp displays are supported\n");
   return 0;
