--- sound.c.orig	Sun Jul  4 11:52:36 1999
+++ sound.c	Tue Nov 26 14:39:57 2002
@@ -23,13 +23,13 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/ipc.h>
 #ifdef USE_PIPE
 #else
 #include <sys/msg.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <X11/Xlib.h>
@@ -39,6 +39,9 @@
 #ifdef linux
 #include <linux/soundcard.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#endif
 #ifdef SOUND_RPLAY
 #include <rplay.h>
 #endif
@@ -147,7 +150,7 @@
 	    {
 	      ton_typ = msgp.mtext[0];
 #endif
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
 	      if (sound_device == SD_DSP)
 		{
 		  int rate = TON_DSP_RATE;
@@ -171,7 +174,7 @@
 	  else
 	    done = True;
 	}
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
       if(sound_device == SD_DSP)
 	ioctl(fd, SNDCTL_DSP_RESET, 0);
 #endif
@@ -248,7 +251,7 @@
   
 } /* Fill_TonBuffer(int ton_low, int ton_high, int korrektur, Bool sndheader)*/
 
-#ifdef linux
+#if ( defined(linux) || defined (__FreeBSD__) )
 Bool Check_DSP(Bool msg)
 {
   int fd;
@@ -374,7 +377,7 @@
     {
       if (debug) fprintf(stderr, "%s: XDisplay is on localhost\n", progname);
 #ifdef SOUND_DSP_AUDIO
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
       Check_DSP(False);
 #endif
       if (sound_device == SD_AUTO) Check_SUN_Audio(False);
@@ -400,7 +403,7 @@
   else
   {
 #ifdef SOUND_DSP_AUDIO
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
     if (sound_device == SD_DSP)
     {
       if (!Check_DSP(True)) sound_device = SD_NONE;
