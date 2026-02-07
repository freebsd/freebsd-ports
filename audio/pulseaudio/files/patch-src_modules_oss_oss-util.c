Support 24bit audio see Comment 6 of 
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198567

--- src/modules/oss/oss-util.c.orig	2022-06-21 10:54:48 UTC
+++ src/modules/oss/oss-util.c
@@ -39,6 +39,22 @@
 
 #include "oss-util.h"
 
+#ifndef DSP_CAP_COPROC
+#define DSP_CAP_COPROC 0x00000800
+#endif
+#ifndef DSP_CAP_TRIGGER
+#define DSP_CAP_TRIGGER 0x00001000
+#endif
+#ifndef DSP_CAP_MMAP
+#define DSP_CAP_MMAP 0x00002000
+#endif
+#ifndef DSP_CAP_MULTI
+#define DSP_CAP_MULTI 0x00004000
+#endif
+#ifndef DSP_CAP_BIND
+#define DSP_CAP_BIND  0x00008000
+#endif
+
 int pa_oss_open(const char *device, int *mode, int* pcaps) {
     static const int nonblock_io = 1;
     int fd = -1;
