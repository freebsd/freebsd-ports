--- lib-src/libnyquist/nyquist/cmt/cext.h.orig	2021-02-04 18:52:51 UTC
+++ lib-src/libnyquist/nyquist/cmt/cext.h
@@ -61,7 +61,7 @@ EXIT(n)  -- calls exit(n) after shutting down/dealloca
 #include <malloc.h>
 #endif
 
-#if NEED_ULONG
+#if NEED_ULONG || __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
