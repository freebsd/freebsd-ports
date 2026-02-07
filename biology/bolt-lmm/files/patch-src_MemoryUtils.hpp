--- src/MemoryUtils.hpp.orig	2022-03-20 13:40:42 UTC
+++ src/MemoryUtils.hpp
@@ -31,8 +31,7 @@ void *ALIGNED_MALLOC(uint64 size);
 #include <mkl.h>
 #define ALIGNED_FREE mkl_free
 #else
-#include <xmmintrin.h>
-#define ALIGNED_FREE _mm_free
+#define ALIGNED_FREE free
 #endif
 
 #define ALIGNED_MALLOC_DOUBLES(numDoubles) (double *) ALIGNED_MALLOC((numDoubles)*sizeof(double))
