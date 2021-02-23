--- src/zmalloc.c.orig	2021-02-23 11:09:32.095861000 -0500
+++ src/zmalloc.c	2021-02-23 11:20:04.491174000 -0500
@@ -40,6 +40,7 @@
     free(ptr);
 }
 
+#include <assert.h>
 #include <string.h>
 #include <pthread.h>
 #include "config.h"
@@ -48,18 +49,14 @@
 
 #ifdef HAVE_MALLOC_SIZE
 #define PREFIX_SIZE (0)
+#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #else
 #if defined(__sun) || defined(__sparc) || defined(__sparc__)
 #define PREFIX_SIZE (sizeof(long long))
 #else
 #define PREFIX_SIZE (sizeof(size_t))
 #endif
-#endif
-
-#if PREFIX_SIZE > 0
 #define ASSERT_NO_SIZE_OVERFLOW(sz) assert((sz) + PREFIX_SIZE > (sz))
-#else
-#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #endif
 
 /* Explicitly override malloc/free etc when using tcmalloc. */
