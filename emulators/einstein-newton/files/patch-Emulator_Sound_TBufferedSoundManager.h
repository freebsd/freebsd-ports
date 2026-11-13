--- Emulator/Sound/TBufferedSoundManager.h.orig	2025-12-19 16:57:53 UTC
+++ Emulator/Sound/TBufferedSoundManager.h
@@ -66,8 +66,10 @@ class TBufferedSoundManager (private)
 private:
 	/// \name Variables
 
+#if TARGET_RT_LITTLE_ENDIAN
 	/// Buffer (for little endian hosts).
 	KUInt8* mBuffer { nullptr };
+#endif
 };
 
 #endif
