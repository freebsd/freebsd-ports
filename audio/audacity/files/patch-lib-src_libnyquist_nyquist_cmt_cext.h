--- lib-src/libnyquist/nyquist/cmt/cext.h.orig	2015-07-11 10:02:22 UTC
+++ lib-src/libnyquist/nyquist/cmt/cext.h
@@ -58,7 +58,7 @@ EXIT(n)  -- calls exit(n) after shutting
 #include <malloc.h>
 #endif
 
-#if NEED_ULONG
+#if NEED_ULONG || __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
