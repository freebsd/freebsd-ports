--- src/rendering/vulkan/thirdparty/vk_mem_alloc/vk_mem_alloc.h.orig	2019-05-03 15:59:56 UTC
+++ src/rendering/vulkan/thirdparty/vk_mem_alloc/vk_mem_alloc.h
@@ -2229,7 +2229,7 @@ remove them if not needed.
 #include <mutex> // for std::mutex
 #include <atomic> // for std::atomic
 
-#if !defined(_WIN32) && !defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
     #include <malloc.h> // for aligned_alloc()
 #endif
 
