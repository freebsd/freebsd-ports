--- examples/sndfile-play.c.orig	Thu Oct 14 18:07:25 2004
+++ examples/sndfile-play.c	Thu Oct 14 18:11:13 2004
@@ -34,7 +34,7 @@
 	#include <sys/time.h>
 #endif
 
-#if defined (__linux__)
+#if defined (__linux__) || defined (__FreeBSD__)
 	#include 	<fcntl.h>
 	#include 	<sys/ioctl.h>
 	#include 	<sys/soundcard.h>
@@ -326,7 +326,7 @@
 **	Linux/OSS functions for playing a sound.
 */
 
-#if defined (__linux__)
+#if defined (__linux__) || defined (__FreeBSD__)
 
 static	int	linux_open_dsp_device (int channels, int srate) ;
 
@@ -869,7 +869,7 @@
 		return 1 ;
 		} ;
 
-#if defined (__linux__)
+#if defined (__linux__) || defined(__FreeBSD__)
 	#if HAVE_ALSA_ASOUNDLIB_H
 		if (access ("/proc/asound/cards", R_OK) == 0)
 			alsa_play (argc, argv) ;
