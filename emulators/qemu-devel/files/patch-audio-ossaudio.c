--- a/audio/ossaudio.c
+++ b/audio/ossaudio.c
@@ -38,6 +38,10 @@
 #define AUDIO_CAP "oss"
 #include "audio_int.h"
 
+#if defined OSS_GETVERSION && defined SNDCTL_DSP_POLICY
+#define USE_DSP_POLICY
+#endif
+
 typedef struct OSSVoiceOut {
     HWVoiceOut hw;
     void *pcm_buf;
@@ -236,14 +240,39 @@ static void oss_dump_info (struct oss_pa
 }
 #endif
 
+#ifdef USE_DSP_POLICY
+static int oss_get_version (int fd, int *version, const char *typ)
+{
+    if (ioctl (fd, OSS_GETVERSION, &version)) {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+        /*
+         * Looks like atm (20100109) FreeBSD knows OSS_GETVERSION
+         * since 7.x, but currently only on the mixer device (or in
+         * the Linuxolator), and in the native version that part of
+         * the code is in fact never reached so the ioctl fails anyway.
+         * Until this is fixed, just check the errno and if its what
+         * FreeBSD's sound drivers return atm assume they are new enough.
+         */
+        if (errno == EINVAL) {
+            *version = 0x040000;
+            return 0;
+        }
+#endif
+        oss_logerr2 (errno, typ, "Failed to get OSS version\n");
+        return -1;
+    }
+    return 0;
+}
+#endif
+
 static int oss_open (int in, struct oss_params *req,
                      struct oss_params *obt, int *pfd)
 {
     int fd;
-    int version;
     int oflags = conf.exclusive ? O_EXCL : 0;
     audio_buf_info abinfo;
     int fmt, freq, nchannels;
+    int setfragment = 1;
     const char *dspname = in ? conf.devpath_in : conf.devpath_out;
     const char *typ = in ? "ADC" : "DAC";
 
@@ -281,27 +310,30 @@ static int oss_open (int in, struct oss_
         goto err;
     }
 
-    if (ioctl (fd, OSS_GETVERSION, &version)) {
-        oss_logerr2 (errno, typ, "Failed to get OSS version\n");
-        version = 0;
-    }
+#ifdef USE_DSP_POLICY
+    if (conf.policy >= 0) {
+        int version;
 
-    if (conf.debug) {
-        dolog ("OSS version = %#x\n", version);
-    }
+        if (!oss_get_version (fd, &version, typ)) {
+            if (conf.debug) {
+                dolog ("OSS version = %#x\n", version);
+            }
 
-#ifdef SNDCTL_DSP_POLICY
-    if (conf.policy >= 0 && version >= 0x040000) {
-        int policy = conf.policy;
-        if (ioctl (fd, SNDCTL_DSP_POLICY, &policy)) {
-            oss_logerr2 (errno, typ, "Failed to set timing policy to %d\n",
-                         conf.policy);
-            goto err;
+            if (version >= 0x040000) {
+                int policy = conf.policy;
+                if (ioctl (fd, SNDCTL_DSP_POLICY, &policy)) {
+                    oss_logerr2 (errno, typ,
+                                 "Failed to set timing policy to %d\n",
+                                 conf.policy);
+                    goto err;
+                }
+                setfragment = 0;
+            }
         }
     }
-    else
 #endif
-    {
+
+    if (setfragment) {
         int mmmmssss = (req->nfrags << 16) | ctz32 (req->fragsize);
         if (ioctl (fd, SNDCTL_DSP_SETFRAGMENT, &mmmmssss)) {
             oss_logerr2 (errno, typ, "Failed to set buffer length (%d, %d)\n",
@@ -857,7 +889,7 @@ static struct audio_option oss_options[]
         .valp  = &conf.exclusive,
         .descr = "Open device in exclusive mode (vmix wont work)"
     },
-#ifdef SNDCTL_DSP_POLICY
+#ifdef USE_DSP_POLICY
     {
         .name  = "POLICY",
         .tag   = AUD_OPT_INT,
