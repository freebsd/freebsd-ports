--- Makefile.PL.orig	Wed Jun 20 16:39:13 2001
+++ Makefile.PL	Thu Oct 10 22:51:15 2002
@@ -17,7 +17,7 @@
 
 $pm_lib = (grep /^X11$/, @ARGV) ? '' : '-lopengl';
 
-$libs = "-lGLU -lGLUT -lGLX $pm_lib -lMesaGLU -lMesaGLUT -lMesaGLX -lglut";
+$libs = "-lglut %%PTHREAD_LIBS%%";
 
 @libs = findlib->ext("$libdirs $libs");
 
