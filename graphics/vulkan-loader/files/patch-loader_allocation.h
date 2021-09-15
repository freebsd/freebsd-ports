--- loader/allocation.h.orig	2021-09-15 16:41:50 UTC
+++ loader/allocation.h
@@ -39,7 +39,7 @@ void loader_device_heap_free(const struct loader_devic
 void *loader_device_heap_realloc(const struct loader_device *device, void *pMemory, size_t orig_size, size_t size,
                                  VkSystemAllocationScope alloc_scope);
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
 #define loader_stack_alloc(size) alloca(size)
 #elif defined(_WIN32)
 #define loader_stack_alloc(size) _alloca(size)
