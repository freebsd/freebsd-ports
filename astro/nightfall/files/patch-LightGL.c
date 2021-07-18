--- LightGL.c.orig	2021-04-26 15:56:57 UTC
+++ LightGL.c
@@ -375,4 +375,7 @@ int WriteJPEGFile(JSAMPLE * imgbuff, char *filename, i
   return(TRUE);
 }
 
+float   texture_minval[NUM_COMP] = {0};
+float   texture_maxval[NUM_COMP] = {0};
+
 #endif /* OpenGL end */
