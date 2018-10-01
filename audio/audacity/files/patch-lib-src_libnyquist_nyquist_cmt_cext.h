--- lib-src/libnyquist/nyquist/cmt/cext.h.orig	2018-10-01 14:07:33 UTC
+++ lib-src/libnyquist/nyquist/cmt/cext.h
@@ -58,7 +58,7 @@ EXIT(n)  -- calls exit(n) after shutting down/dealloca
 #include <malloc.h>
 #endif
 
-#if NEED_ULONG
+#if NEED_ULONG || __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
