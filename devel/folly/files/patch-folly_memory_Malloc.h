--- folly/memory/Malloc.h.orig	2019-06-16 07:28:42 UTC
+++ folly/memory/Malloc.h
@@ -96,11 +96,11 @@ mallctlbymib(const size_t*, size_t, void*, size_t*, vo
 // for malloc_usable_size
 // NOTE: FreeBSD 9 doesn't have malloc.h.  Its definitions
 // are found in stdlib.h.
-#if __has_include(<malloc.h>)
-#include <malloc.h>
-#else
+//#if __has_include(<malloc.h>)
+//#include <malloc.h>
+//#else
 #include <stdlib.h>
-#endif
+//#endif
 
 #include <cassert>
 #include <cstddef>
