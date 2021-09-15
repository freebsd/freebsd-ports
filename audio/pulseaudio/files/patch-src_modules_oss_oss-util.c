Support 24bit audio see Comment 6 of 
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198567

--- src/modules/oss/oss-util.c.orig	2018-07-13 19:06:14 UTC
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
@@ -348,7 +364,7 @@ int pa_oss_get_hw_description(const char
     }
 
     while (!feof(f)) {
-        char line[64];
+        char line[1024];
         int device;
 
         if (!fgets(line, sizeof(line), f))
@@ -357,14 +373,22 @@ int pa_oss_get_hw_description(const char
         line[strcspn(line, "\r\n")] = 0;
 
         if (!b) {
+#ifdef __FreeBSD__
+            b = pa_streq(line, "Installed devices:");
+#else
             b = pa_streq(line, "Audio devices:");
+#endif
             continue;
         }
 
         if (line[0] == 0)
             break;
 
+#ifdef __FreeBSD__
+        if (sscanf(line, "pcm%i: ", &device) != 1)
+#else
         if (sscanf(line, "%i: ", &device) != 1)
+#endif
             continue;
 
         if (device == n) {
@@ -376,7 +400,16 @@ int pa_oss_get_hw_description(const char
             if (pa_endswith(k, " (DUPLEX)"))
                 k[strlen(k)-9] = 0;
 
-            pa_strlcpy(name, k, l);
+            if (*k == '<') {
+                char *e = strrchr(k, '>');
+
+                if (e) {
+                    *e = 0;
+                    ++k;
+                }
+            }
+            // Include the number to disambiguate devices with the same name
+            pa_snprintf(name, l, "%d: %s", device, k);
             r = 0;
             break;
         }
