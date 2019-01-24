Revert https://github.com/RPCS3/rpcs3/commit/d4591b15083b as ALSA on
FreeBSD can only use plugins i.e., no kernel support.

--- rpcs3/Emu/Audio/ALSA/ALSABackend.cpp.orig	2019-01-22 20:10:17 UTC
+++ rpcs3/Emu/Audio/ALSA/ALSABackend.cpp
@@ -139,7 +139,7 @@ bool ALSABackend::AddData(const void* src, u32 num_sam
 		return false;
 	}
 
-	if (false)
+	if (res < 0)
 	{
 		res = snd_pcm_recover(tls_handle, res, 0);
 
