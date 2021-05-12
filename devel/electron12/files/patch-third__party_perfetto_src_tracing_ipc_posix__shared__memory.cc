--- third_party/perfetto/src/tracing/ipc/posix_shared_memory.cc.orig	2021-04-14 01:15:27 UTC
+++ third_party/perfetto/src/tracing/ipc/posix_shared_memory.cc
@@ -18,7 +18,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 #include <fcntl.h>
 #include <stdint.h>
@@ -132,4 +133,4 @@ std::unique_ptr<SharedMemory> PosixSharedMemory::Facto
 
 }  // namespace perfetto
 
-#endif  // OS_LINUX || OS_ANDROID || OS_APPLE
+#endif  // OS_LINUX || OS_ANDROID || OS_APPLE || OS_FREEBSD
