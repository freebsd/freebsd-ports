--- ffmpeg-strip-wma/mem.c.orig	Thu Feb 26 12:25:16 2004
+++ ffmpeg-strip-wma/mem.c	Thu Feb 26 11:43:42 2004
@@ -29,6 +29,9 @@
 #undef free
 #undef realloc
 
+#undef HAVE_MEMALIGN
+#undef HAVE_MALLOC_H
+
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
 #endif
