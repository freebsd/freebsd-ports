--- io/soundcard/unix/linux/soundcardpmo.cpp.orig	Fri May 30 20:01:42 2003
+++ io/soundcard/unix/linux/soundcardpmo.cpp	Thu Aug 21 21:48:48 2003
@@ -210,7 +210,7 @@
    int       junkvar = 0;
 
 #if !SMALL_ENDIAN 
-    mask = AFMT_S16_BE
+    mask = AFMT_S16_BE;
     if(ioctl(audio_fd,SNDCTL_DSP_SETFMT,&mask) == -1){
 	ReportError(_("Cannot set card to Big Endian."));
 	return(Error) pmoError_IOCTL_SNDCTL_DSP_SETFMT;
