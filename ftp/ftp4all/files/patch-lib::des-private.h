--- lib/des-private.h.orig	Thu Sep 24 15:02:11 1998
+++ lib/des-private.h	Mon Feb  9 19:41:07 2004
@@ -10,6 +10,12 @@
 #ifdef i386
 #define LITTLE_ENDIAN 1
 #endif
+#ifdef __ia64
+#define LITTLE_ENDIAN 1
+#endif
+#ifdef __amd64
+#define LITTLE_ENDIAN 1
+#endif
 #ifdef sun386
 #define LITTLE_ENDIAN 1
 #endif
