--- coders/jp2.c.orig	Sat Oct 12 23:41:32 2002
+++ coders/jp2.c	Wed Jan 22 21:11:31 2003
@@ -639,5 +639,14 @@
 
 #if defined(HasJP2)
+
+#ifndef JAS_IMAGE_CM_GRAY
+#define JAS_IMAGE_CM_GRAY JAS_IMAGE_CS_GRAY
+#endif
+
+#ifndef JAS_IMAGE_CM_RGB
+#define JAS_IMAGE_CM_RGB JAS_IMAGE_CS_RGB
+#endif
+
 /*
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %                                                                             %
