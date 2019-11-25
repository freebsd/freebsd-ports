--- skia/ext/SkMemory_new_handler.cpp.orig	2019-09-10 10:42:44 UTC
+++ skia/ext/SkMemory_new_handler.cpp
@@ -77,7 +77,7 @@ static void* malloc_nothrow(size_t size) {
   // TODO(b.kelemen): we should always use UncheckedMalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = malloc(size);
 #else
     // It's the responsibility of the caller to check the return value.
@@ -97,7 +97,7 @@ static void* calloc_nothrow(size_t size) {
   // TODO(b.kelemen): we should always use UncheckedCalloc but currently it
   // doesn't work as intended everywhere.
   void* result;
-#if  defined(OS_IOS)
+#if  defined(OS_IOS) || defined(OS_BSD)
     result = calloc(1, size);
 #else
     // It's the responsibility of the caller to check the return value.
