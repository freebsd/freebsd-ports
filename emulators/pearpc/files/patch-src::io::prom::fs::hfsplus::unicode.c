--- src/io/prom/fs/hfsplus/unicode.c.DIST       Thu May  6 10:45:32 2004
+++ src/io/prom/fs/hfsplus/unicode.c    Tue May 25 10:06:24 2004
@@ -28,6 +28,16 @@
 
 #include "unicode.h"
 
+#ifdef FREEBSD_MB_SUPPORT
+size_t  mbrtowc __P((wchar_t * __restrict, const char * __restrict, size_t,
+                    mbstate_t * __restrict));
+size_t  wcrtomb __P((char * __restrict, wchar_t, mbstate_t * __restrict));
+
+#include "mbrtowc.c"
+#include "wcrtomb.c"
+#endif /* FREEBSD_MB_SUPPORT */
+
+
 /* convert the asci string astr into a unicode string given by ustr.
  *
  * ToDo: Think about better error handling ?
