--- X.c.orig	1997-02-13 17:53:43 UTC
+++ X.c
@@ -290,7 +290,7 @@ int InitMachine(void)
  DefaultGC=DefaultGCOfScreen (Scr);
  DefaultCMap=DefaultColormapOfScreen (Scr);
  bpp=DefaultDepthOfScreen (Scr);
- if (bpp!=8 && bpp!=16 && bpp!=32)
+ if (bpp!=8 && bpp!=16 && bpp!=24 && bpp!=32)
  {
   printf ("FAILED - Only 8,16 and 32 bpp displays are supported\n");
   return 0;
