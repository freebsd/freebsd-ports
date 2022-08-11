--- skia/ext/SkMemory_new_handler.cpp.orig	2022-05-19 03:45:39 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -79,7 +79,7 @@ static void* malloc_nothrow(size_t size) {
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   result = malloc(size);
 #else
   // It's the responsibility of the caller to check the return value.
