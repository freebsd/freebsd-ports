$OpenBSD: patch-audio_h,v 1.1 2009/03/28 16:26:46 martynas Exp $
--- audio.h.orig	2004-01-23 09:41:31 UTC
+++ audio.h
@@ -98,6 +98,7 @@ audio_ctlfunc_t audio_jaguar;
 audio_ctlfunc_t audio_nas;
 audio_ctlfunc_t audio_oss;
 audio_ctlfunc_t audio_qnx;
+audio_ctlfunc_t audio_sndio;
 audio_ctlfunc_t audio_sun;
 audio_ctlfunc_t audio_win32;
 
