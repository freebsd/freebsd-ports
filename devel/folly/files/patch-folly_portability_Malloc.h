--- folly/portability/Malloc.h.orig	2019-06-16 07:29:29 UTC
+++ folly/portability/Malloc.h
@@ -26,7 +26,7 @@
 // malloc_usable_size, and that's what we should be using.
 #include <jemalloc/jemalloc.h> // @manual
 #else
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
