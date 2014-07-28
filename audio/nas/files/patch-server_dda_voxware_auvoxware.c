--- server/dda/voxware/auvoxware.c.orig	2008-05-14 22:35:08.000000000 +0400
+++ server/dda/voxware/auvoxware.c	2008-05-14 22:40:32.000000000 +0400
@@ -133,7 +133,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#ifndef SVR4
+#if !defined(SVR4) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 #include <sys/types.h>
@@ -183,7 +183,9 @@
 # else
 #  include <machine/soundcard.h>
 # endif
+/* PC Speaker functions seems to be unused here
 # include <machine/pcaudioio.h>
+*/
 #else
 # ifdef __NetBSD__
 #  include <sys/ioctl.h>
@@ -875,7 +877,11 @@
         if (sndStatOut.fd == -1) {
             while ((sndStatOut.fd = open(sndStatOut.device,
                                          sndStatOut.
+#if defined(__FreeBSD__)
+                                         howToOpen | extramode,
+#else
                                          howToOpen | O_SYNC | extramode,
+#endif
                                          0666)) == -1 && wait) {
                 osLogMsg("openDevice: waiting on output device\n");
                 sleep(1);
@@ -1618,6 +1624,11 @@
 /*
  * Setup soundcard at maximum audio quality.
  */
+
+#if defined(__FreeBSD__)
+#define NO_16_BIT_SAMPLING
+#endif
+
 static void
 setupSoundcard(SndStat * sndStatPtr)
 {
@@ -1880,7 +1891,11 @@
                              sndStatOut.device, sndStatOut.howToOpen);
 
                 if ((fd = open(sndStatOut.device,
+#if defined(__FreeBSD__)
+                               sndStatOut.howToOpen | extramode,
+#else
                                sndStatOut.howToOpen | O_SYNC | extramode,
+#endif
                                0)) == -1) {
                     UNIDENTMSG;
                     osLogMsg("Init: Output open(%s) failed: %s\n",
