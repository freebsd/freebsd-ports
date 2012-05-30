--- lib-src/libnyquist/nyquist/cmt/cext.h       2009-07-15 20:27:36.000000000 -0700
+++ lib-src/libnyquist/nyquist/cmt/cext.h       2009-07-19 00:37:45.000000000 -0700

@@ -58,7 +58,7 @@
 #include <malloc.h>
 #endif

-#if NEED_ULONG
+#if NEED_ULONG || __FreeBSD__
 typedef unsigned long ulong;
 #endif

