--- Sources/Sound/SoundProviders/Unix/soundprovider_recorder_oss.cpp.orig	Tue Sep 23 07:15:13 2003
+++ Sources/Sound/SoundProviders/Unix/soundprovider_recorder_oss.cpp	Tue Oct 21 02:52:21 2003
@@ -34,6 +34,13 @@
 #include <sys/select.h>
 #endif
 
+#if !defined(AFMT_S16_NE)
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
 
 /////////////////////////////////////////////////////////////////////////////
 // CL_SoundProvider_Recorder_OSS_Session construction:
