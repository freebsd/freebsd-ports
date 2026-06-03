--- extern/audaspace/plugins/ffmpeg/FFMPEGReader.h.orig	2025-12-28 19:32:23 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGReader.h
@@ -107,11 +107,6 @@ class AUD_PLUGIN_API FFMPEGReader : public IReader (pr
 	std::shared_ptr<Buffer> m_membuffer;
 
 	/**
-	 * The buffer to read with.
-	 */
-	data_t* m_membuf;
-
-	/**
 	 * Reading position of the buffer.
 	 */
 	long long m_membufferpos;
