--- thirdparty/thekla_atlas/nvcore/Memory.cpp.orig	2017-12-29 15:53:28 UTC
+++ thirdparty/thekla_atlas/nvcore/Memory.cpp
@@ -6,10 +6,6 @@
 
 #include <stdlib.h>
 
-#ifdef NV_OS_LINUX
-#include <malloc.h>
-#endif
-
 #define USE_EFENCE 0
 
 #if USE_EFENCE
@@ -130,7 +126,7 @@ void * nv::aligned_malloc(size_t size, s
 
 #if NV_OS_WIN32 || NV_OS_DURANGO
     return _aligned_malloc(size, alignment);
-#elif NV_OS_DARWIN && !NV_OS_IOS
+#elif (NV_OS_FREEBSD || NV_OS_DARWIN) && !NV_OS_IOS
     void * ptr = NULL;
     posix_memalign(&ptr, alignment, size);
     return ptr;
