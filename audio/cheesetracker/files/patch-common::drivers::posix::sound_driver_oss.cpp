--- common/drivers/posix/sound_driver_oss.cpp.orig	Mon Jun 23 10:06:42 2003
+++ common/drivers/posix/sound_driver_oss.cpp	Fri Jul 11 11:49:31 2003
@@ -40,6 +40,14 @@
 
 #define DEFAULT_AUDIO_DEVICE "/dev/dsp"
 
+#if !defined(AFMT_S16_NE)
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
+
 
 bool Sound_Driver_OSS::does_perform_disk_write() {
 
