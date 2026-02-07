--- clunk/sse_fft_context.cpp.orig	2011-11-09 20:57:22.000000000 +0600
+++ clunk/sse_fft_context.cpp	2011-11-09 20:58:53.371320298 +0600
@@ -1,5 +1,4 @@
 #include <stdlib.h>
-#include <malloc.h>
 #include <stdio.h>
 #include <new>
 #include "fft_context.h"
@@ -12,7 +12,8 @@
 #ifdef _WINDOWS
 	ptr = _aligned_malloc(size, alignment);
 #else
-	ptr = memalign(alignment, size);
+	if (posix_memalign(&ptr, alignment, size))
+		ptr = NULL;
 #endif
 	if (ptr == NULL)
 		throw std::bad_alloc();
