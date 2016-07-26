--- lib-src/libnyquist/nyquist/cmt/cext.h.orig	2016-07-26 13:34:07 UTC
+++ lib-src/libnyquist/nyquist/cmt/cext.h
@@ -58,7 +58,7 @@ EXIT(n)  -- calls exit(n) after shutting
 #include <malloc.h>
 #endif
 
-#if NEED_ULONG
+#if NEED_ULONG || __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
