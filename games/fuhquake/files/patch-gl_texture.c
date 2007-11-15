--- gl_texture.c.orig	2007-11-15 00:10:30.000000000 +0600
+++ gl_texture.c	2007-11-15 00:10:38.000000000 +0600
@@ -159,7 +159,7 @@
 }
 
 static GLenum oldtarget = GL_TEXTURE0_ARB;
-static int cnttextures[4] = {-1, -1, -1, -1};   
+int cnttextures[4] = {-1, -1, -1, -1};   
 static qboolean mtexenabled = false;
 
 
