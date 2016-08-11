Support 24bit audio see Comment 6 of 
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198567

--- src/modules/oss/oss-util.c.orig	2015-09-10 04:51:41 UTC
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
     int fd = -1;
     int caps;
@@ -164,8 +180,8 @@ int pa_oss_auto_format(int fd, pa_sample
         [PA_SAMPLE_FLOAT32BE] = AFMT_QUERY, /* not supported */
         [PA_SAMPLE_S32LE] = AFMT_QUERY, /* not supported */
         [PA_SAMPLE_S32BE] = AFMT_QUERY, /* not supported */
-        [PA_SAMPLE_S24LE] = AFMT_QUERY, /* not supported */
-        [PA_SAMPLE_S24BE] = AFMT_QUERY, /* not supported */
+        [PA_SAMPLE_S24LE] = AFMT_S24_LE,
+        [PA_SAMPLE_S24BE] = AFMT_S24_BE,
         [PA_SAMPLE_S24_32LE] = AFMT_QUERY, /* not supported */
         [PA_SAMPLE_S24_32BE] = AFMT_QUERY, /* not supported */
     };
