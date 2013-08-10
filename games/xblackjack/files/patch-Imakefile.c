--- Imakefile.orig	1993-06-18 19:17:45.000000000 +0200
+++ Imakefile	2013-08-10 16:54:28.755342996 +0200
@@ -54,7 +54,7 @@
 /*
  *  You may need to remove -lbsd.
  */
-  EXTRA_LIBRARIES = -lXm $(DEPLIBS) -lbsd
+  EXTRA_LIBRARIES = -lXm -lXt -lXmu -lXext -lX11
 #endif
 
 /*
