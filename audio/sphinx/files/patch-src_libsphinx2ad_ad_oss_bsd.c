$FreeBSD$

author:  Andriy Gapon

--- src/libsphinx2ad/ad_oss_bsd.c.orig	Thu Dec 13 21:11:27 2001
+++ src/libsphinx2ad/ad_oss_bsd.c	Fri Oct 24 04:11:22 2003
@@ -61,7 +61,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <errno.h>
 
 #include "s2types.h"
@@ -72,14 +72,11 @@
 
 #define SPS_EPSILON   200
 
-#ifndef SNDCTL_DSP_SETDUPLEX
-#define SNDCTL_DSP_SETDUPLEX -1
-#endif
 
 ad_rec_t *ad_open_sps (int32 sps) {
     ad_rec_t *handle;
     int32 dspFD, mixerFD;
-    int32 nonBlocking=1, sourceMic=1, inputGain=INPUT_GAIN;
+    int32 sourceMic=1, inputGain=INPUT_GAIN;
     int32 audioFormat=AUDIO_FORMAT;
     int32 dspCaps=0;
     int32 sampleRate;
@@ -96,7 +93,6 @@
     }
     sampleRate = sps;
     
-    /* Used to have O_NDELAY. */
     if((dspFD = open ("/dev/dsp", O_RDONLY))<0){
 	if (errno == EBUSY)
 	    fprintf(stderr, "Audio device busy\n");
@@ -105,18 +101,6 @@
 	return NULL;
     }
     
-    if (ioctl (dspFD, SNDCTL_DSP_SYNC, 0) < 0){
-	fprintf(stderr, "Audio ioctl(SYNC) failed: %s\n", strerror(errno));
-	close (dspFD);
-	return NULL;
-    }
-    
-    if (ioctl (dspFD, SNDCTL_DSP_RESET, 0) < 0){
-	fprintf(stderr, "Audio ioctl(RESET) failed: %s\n", strerror(errno));
-	close (dspFD);
-	return NULL;
-    }
-    
     if (ioctl (dspFD, SNDCTL_DSP_SETFMT, &audioFormat) < 0){
 	fprintf(stderr, "Audio ioctl(SETFMT 0x%x) failed: %s\n", audioFormat, strerror(errno));
 	close (dspFD);
@@ -139,12 +123,6 @@
 	return NULL;
     }
     
-    if (ioctl (dspFD, SNDCTL_DSP_NONBLOCK, &nonBlocking) < 0) {
-	fprintf(stderr, "ioctl(NONBLOCK) failed: %s\n", strerror(errno));
-	close (dspFD);
-	return NULL;
-    }
-    
     if (ioctl (dspFD, SNDCTL_DSP_GETCAPS, &dspCaps) < 0) {
 	fprintf(stderr, "ioctl(GETCAPS) failed: %s\n", strerror(errno));
 	close (dspFD);
@@ -161,8 +139,6 @@
     printf("DSP %s memory map capability.\n", (dspCaps&DSP_CAP_MMAP)?"has":"does not have");
 #endif
     
-    if ((dspCaps & DSP_CAP_DUPLEX) && (ioctl (dspFD, SNDCTL_DSP_SETDUPLEX, 0) < 0))
-	fprintf(stderr, "ioctl(SETDUPLEX) failed: %s\n", strerror(errno));
     
   /* Patched by N. Roy (nickr@ri.cmu.edu), 99/7/23. 
      Previously, mixer was set through dspFD. This is incorrect. Should
@@ -210,10 +186,10 @@
   }
     
   handle->dspFD = dspFD;
-  handle->recording = 0;
   handle->sps = sps;
   handle->bps = sizeof(int16);
-
+  handle->recording = 1;
+  
   return(handle);
 }
 
@@ -224,15 +200,10 @@
 
 int32 ad_close (ad_rec_t *handle)
 {
-    if (handle->dspFD < 0)
-	return AD_ERR_NOT_OPEN;
-    
     if (handle->recording) {
-	if (ad_stop_rec (handle) < 0)
-	    return AD_ERR_GEN;
+	ad_stop_rec (handle);
     }
     
-    close (handle->dspFD);
     free(handle);
     
     return(0);
@@ -240,48 +211,62 @@
 
 int32 ad_start_rec (ad_rec_t *handle)
 {
-    if (handle->dspFD < 0)
-	return AD_ERR_NOT_OPEN;
-    
-    if (handle->recording)
-	return AD_ERR_GEN;
+
+    if (!handle->recording) {
+	    
+	int32 dspFD;
+	int32 audioFormat=AUDIO_FORMAT;
+	int32 sampleRate=handle->sps;
+	
+	if((dspFD = open ("/dev/dsp", O_RDONLY))<0){
+	    if (errno == EBUSY)
+	        fprintf(stderr, "Audio device busy\n");
+	    else
+		fprintf(stderr, "Failed to open audio device: %s\n", strerror(errno));
+	    return AD_ERR_GEN;
+	}
     
-    /* Sample rate, format, input mix settings, &c. are configured
-     * with ioctl(2) calls under Linux. It makes more sense to handle
-     * these at device open time and consider the state of the device
-     * to be fixed until closed.
-     */
+	if (ioctl (dspFD, SNDCTL_DSP_SETFMT, &audioFormat) < 0){
+	    fprintf(stderr, "Audio ioctl(SETFMT 0x%x) failed: %s\n", audioFormat, strerror(errno));
+	    close (dspFD);
+	    return AD_ERR_GEN;
+	}
+	if (audioFormat != AUDIO_FORMAT) {
+	    fprintf(stderr, "Audio ioctl(SETFMT): 0x%x, expected: 0x%x\n", audioFormat, AUDIO_FORMAT);
+	    close (dspFD);
+	    return AD_ERR_GEN;
+	}
     
-    handle->recording = 1;
-
-    /* rkm@cs: This doesn't actually do anything.  How do we turn recording on/off? */
+	if (ioctl (dspFD, SNDCTL_DSP_SPEED, &sampleRate) < 0) {
+	    fprintf(stderr, "Audio ioctl(SPEED %d) failed %s\n", sampleRate, strerror(errno));
+	    close (dspFD);
+	    return AD_ERR_GEN;
+	}
+	if (sampleRate != handle->sps) {
+	    fprintf(stderr, "Audio ioctl(SPEED): %d, expected: %d\n", sampleRate, handle->sps);
+	    close (dspFD);
+	    return AD_ERR_GEN;
+	}
+	handle->dspFD = dspFD;
+	handle->recording = 1;
+    }
 
     return(0);
 }
 
 int32 ad_stop_rec (ad_rec_t *handle)
 {
-    if (handle->dspFD < 0)
-	return AD_ERR_NOT_OPEN;
-    
-    if (! handle->recording)
-	return AD_ERR_GEN;
-    
-    if (ioctl (handle->dspFD, SNDCTL_DSP_SYNC, 0) < 0) {
-	fprintf(stderr, "Audio ioctl(SYNC) failed: %s\n", strerror(errno));
-	return AD_ERR_GEN;
-    }
-    
-    handle->recording = 0;
-    
+    if (handle->recording) {
+	close (handle->dspFD);
+	handle->dspFD = -1;
+	handle->recording = 0;
+    }    
     return (0);
 }
 
 int32 ad_read (ad_rec_t *handle, int16 *buf, int32 max)
 {
-    int32 length;
-    
-    length = max * handle->bps;		/* #samples -> #bytes */
+    int32 length = max * handle->bps;		/* #samples -> #bytes */
     
     if ((length = read (handle->dspFD, buf, length)) > 0) {
 #if 0
@@ -292,7 +277,7 @@
     }
     
     if (length < 0) {
-	fprintf(stderr, "Audio read error\n");
+	perror("Audio read error");
 	return AD_ERR_GEN;
     }
     
