--- Sources/Sound/Unix/soundoutput_oss.cpp.orig	Fri Aug 22 19:32:54 2003
+++ Sources/Sound/Unix/soundoutput_oss.cpp	Mon Sep  8 01:45:46 2003
@@ -34,6 +34,14 @@
 #include <sys/select.h>
 #endif
 
+#if !defined(AFMT_S16_NE)
+#if defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)
+#define AFMT_S16_NE AFMT_S16_BE
+#else
+#define AFMT_S16_NE AFMT_S16_LE
+#endif
+#endif
+
 /////////////////////////////////////////////////////////////////////////////
 // CL_SoundOutput_OSS construction:
 
