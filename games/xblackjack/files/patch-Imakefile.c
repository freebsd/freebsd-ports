--- Imakefile.orig	Wed Oct 30 22:39:10 2002
+++ Imakefile	Wed Oct 30 22:39:40 2002
@@ -54,7 +54,7 @@
 /*
  *  You may need to remove -lbsd.
  */
-  EXTRA_LIBRARIES = -lXm $(DEPLIBS) -lbsd
+  EXTRA_LIBRARIES = ${MOTIFLIB} -lXt -lXmu -lXext -lX11
 #endif
 
 /*
