--- lib/des-private.h.orig	Tue May  6 07:48:47 2003
+++ lib/des-private.h	Tue May  6 07:28:57 2003
@@ -10,6 +10,9 @@
 #ifdef i386
 #define LITTLE_ENDIAN 1
 #endif
+#ifdef __ia64
+#define LITTLE_ENDIAN 1
+#endif
 #ifdef sun386
 #define LITTLE_ENDIAN 1
 #endif
