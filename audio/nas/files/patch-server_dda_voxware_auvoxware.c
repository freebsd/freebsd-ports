--- server/dda/voxware/auvoxware.c.orig	2013-08-13 18:50:30 UTC
+++ server/dda/voxware/auvoxware.c
@@ -133,7 +133,7 @@ PERFORMANCE OF THIS SOFTWARE.
 
 #include <stdio.h>
 #include <stdlib.h>
-#ifndef SVR4
+#if !defined(SVR4) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 #include <sys/types.h>
@@ -183,7 +183,9 @@ static int debug_msg_indentation = 0;
 # else
 #  include <machine/soundcard.h>
 # endif
+/* PC Speaker functions seems to be unused here
 # include <machine/pcaudioio.h>
+*/
 #else
 # ifdef __NetBSD__
 #  include <sys/ioctl.h>
@@ -875,7 +877,11 @@ openDevice(AuBool wait)
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
@@ -1624,6 +1630,11 @@ setWritePhysicalOutputFunction(CompiledF
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
@@ -1886,7 +1897,11 @@ AuInitPhysicalDevices(void)
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
