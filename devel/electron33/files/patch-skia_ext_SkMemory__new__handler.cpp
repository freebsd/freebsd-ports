--- skia/ext/SkMemory_new_handler.cpp.orig	2024-06-18 21:43:38 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -19,7 +19,7 @@
 #include <windows.h>
 #elif BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
-#else
+#elif !BUILDFLAG(IS_BSD)
 #include <malloc.h>
 #endif
 
@@ -105,7 +105,7 @@ static void* malloc_nothrow(size_t size, int debug_sen
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
