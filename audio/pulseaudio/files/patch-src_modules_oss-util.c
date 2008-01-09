--- modules/oss-util.c.orig	2007-11-08 21:45:25.000000000 -0500
+++ modules/oss-util.c	2008-01-09 17:00:45.000000000 -0500
@@ -44,6 +44,22 @@
 
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
     int fd = -1;
     int caps;
@@ -300,7 +316,11 @@ static int get_device_number(const char 
     int r;
 
     if (!(p = rp = pa_readlink(dev))) {
+#ifdef ENOLINK
         if (errno != EINVAL && errno != ENOLINK) {
+#else
+        if (errno != EINVAL) {
+#endif
             r = -1;
             goto finish;
         }
