--- backends/oss/oss-backend.c.orig	2017-03-12 15:28:02 UTC
+++ backends/oss/oss-backend.c
@@ -40,6 +40,8 @@
      * from the sndstat file, but avoid even trying that on systems where this
      * is not needed and the file is not present */
 #define OSS_PATH_SNDSTAT  "/dev/sndstat"
+    /* remove SOUND_MIXER_INFO on FreeBSD, use OSS_PATH_SNDSTAT */
+#undef SOUND_MIXER_INFO
 #endif
 
 #define OSS_MAX_DEVICES   32
@@ -377,6 +379,10 @@ read_device_label (OssBackend *oss, cons
 {
     guint index;
 
+    /* default_device setting only in read_device_label_sndstat()
+     * on FreeBSD use OSS_PATH_SNDSTAT
+     */
+
 #ifdef SOUND_MIXER_INFO
     do {
         struct mixer_info info;
@@ -430,6 +436,7 @@ read_device_label_sndstat (OssBackend  *
 
     while (fgets (line, sizeof (line), fp) != NULL) {
         gchar *p;
+        g_strchomp(line); // required for g_str_has_suffix()
 
         if (g_str_has_prefix (line, prefix) == FALSE)
             continue;
