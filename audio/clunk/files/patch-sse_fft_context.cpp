--- sse_fft_context.cpp.orig	2009-08-05 01:28:34.000000000 +0400
+++ sse_fft_context.cpp	2010-04-13 04:16:03.000000000 +0400
@@ -1,5 +1,4 @@
 #include <stdlib.h>
-#include <malloc.h>
 #include <stdio.h>
 #include <new>
 #include "fft_context.h"
@@ -9,20 +8,11 @@
 
 void * aligned_allocator::allocate(size_t size, size_t alignment) {
 	void * ptr;
-#ifdef _WINDOWS
-	ptr = _aligned_malloc(size, alignment);
-#else
-	ptr = memalign(alignment, size);
-#endif
-	if (ptr == NULL)
+	if (posix_memalign(&ptr, alignment, size) != 0)
 		throw std::bad_alloc();
 	return ptr;
 }
 
 void aligned_allocator::deallocate(void *ptr) {
-#ifdef _WINDOWS
-	_aligned_free(ptr);
-#else
 	free(ptr);
-#endif
 }
