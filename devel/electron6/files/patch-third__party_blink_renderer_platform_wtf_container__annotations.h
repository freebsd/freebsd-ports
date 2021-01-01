--- third_party/blink/renderer/platform/wtf/container_annotations.h.orig	2019-09-10 10:42:49 UTC
+++ third_party/blink/renderer/platform/wtf/container_annotations.h
@@ -10,7 +10,7 @@
 
 // TODO(ochang): Remove the ARCH_CPU_X86_64 condition to enable this for X86
 // once the crashes there have been fixed: http://crbug.com/461406
-#if defined(ADDRESS_SANITIZER) && defined(OS_LINUX) && defined(ARCH_CPU_X86_64)
+#if defined(ADDRESS_SANITIZER) && (defined(OS_LINUX) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 #define ANNOTATE_CONTIGUOUS_CONTAINER
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)                       \
   if (buffer) {                                                              \
@@ -35,13 +35,13 @@
   ANNOTATE_NEW_BUFFER(buffer, newCapacity, bufferSize);
 // Annotations require buffers to begin on an 8-byte boundary.
 
-#else  // ADDRESS_SANITIZER && OS_LINUX && ARCH_CPU_X86_64
+#else  // ADDRESS_SANITIZER && (OS_LINUX || OS_BSD) && ARCH_CPU_X86_64
 
 #define ANNOTATE_NEW_BUFFER(buffer, capacity, newSize)
 #define ANNOTATE_DELETE_BUFFER(buffer, capacity, oldSize)
 #define ANNOTATE_CHANGE_SIZE(buffer, capacity, oldSize, newSize)
 #define ANNOTATE_CHANGE_CAPACITY(buffer, oldCapacity, bufferSize, newCapacity)
 
-#endif  // ADDRESS_SANITIZER && OS_LINUX && ARCH_CPU_X86_64
+#endif  // ADDRESS_SANITIZER && (OS_LINUX || OS_BSD) && ARCH_CPU_X86_64
 
 #endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_WTF_CONTAINER_ANNOTATIONS_H_
