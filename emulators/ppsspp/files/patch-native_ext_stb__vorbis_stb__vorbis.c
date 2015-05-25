--- native/ext/stb_vorbis/stb_vorbis.c.orig	2015-02-23 23:22:58 UTC
+++ native/ext/stb_vorbis/stb_vorbis.c
@@ -15,7 +15,8 @@
 #pragma warning (disable:4996)
 #pragma warning (disable:4244)
 #include <malloc.h>
-#elif !defined(__SYMBIAN32__)
+#elif !defined(__SYMBIAN32__) && !defined(__DragonFly__) && \
+      !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #include <alloca.h>
 #endif
 
