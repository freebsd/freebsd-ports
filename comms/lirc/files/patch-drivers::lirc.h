--- drivers/lirc.h.orig
+++ drivers/lirc.h
@@ -9,12 +9,17 @@
 #if defined(__linux__)
 #include <linux/types.h>
 #include <linux/ioctl.h>
-#elif defined(_NetBSD_)
+#elif defined(_NetBSD_) || defined(__FreeBSD__)
 #include <sys/ioctl.h>
 #elif defined(_CYGWIN_)
 #define __USE_LINUX_IOCTL_DEFS
 #include <sys/ioctl.h>
 #endif
+#ifndef __linux__
+#include <stdint.h>
+#define __u32 uint32_t
+#define __u64 uint64_t
+#endif
 
 #define PULSE_BIT       0x01000000
 #define PULSE_MASK      0x00FFFFFF
