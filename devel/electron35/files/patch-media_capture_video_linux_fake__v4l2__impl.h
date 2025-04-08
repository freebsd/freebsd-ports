--- media/capture/video/linux/fake_v4l2_impl.h.orig	2023-10-19 19:58:26 UTC
+++ media/capture/video/linux/fake_v4l2_impl.h
@@ -8,7 +8,13 @@
 #include <map>
 #include <string>
 
+#include "build/build_config.h"
+#if BUILDFLAG(IS_OPENBSD)
+#include <sys/videoio.h>
+typedef __uint32_t __u32;
+#else
 #include <linux/videodev2.h>
+#endif
 
 #include "base/synchronization/lock.h"
 #include "media/capture/capture_export.h"
@@ -38,7 +44,7 @@ class CAPTURE_EXPORT FakeV4L2Impl : public V4L2Capture
   // Implementation of V4L2CaptureDevice interface:
   int open(const char* device_name, int flags) override;
   int close(int fd) override;
-  int ioctl(int fd, int request, void* argp) override;
+  int ioctl(int fd, unsigned long request, void* argp) override;
   void* mmap(void* start,
              size_t length,
              int prot,
