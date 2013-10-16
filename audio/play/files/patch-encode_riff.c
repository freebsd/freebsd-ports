--- encode_riff.c.orig	Tue Mar 25 16:25:07 1997
+++ encode_riff.c	Thu Aug 19 14:37:52 2004
@@ -11,7 +11,7 @@
 #include <signal.h>
 #include <err.h>
 
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "play.h"
 #include "encode_riff.h"
@@ -74,7 +74,7 @@
     char *bufp;
     char *device;
     int devfd, filefd;
-    int stat, len, buf_size, format, data_length;
+    int stat, len, buf_size, format = 0, data_length;
 
     if (!f_hasdsp) {
 	fprintf(stderr, "%s: %s: needs DSP for play\n", myname, audio_file);
@@ -109,7 +109,12 @@
 	warn("%s", device);
 	stat = FAIL; goto failplay0;
     }
+#if 0
+    /* this (at least under fbsd) means that you want to set play format
+     * to headerp->sample_size which is a nonsense */
     if (ioctl(devfd, SNDCTL_DSP_SAMPLESIZE, &headerp->sample_size) < 0) {
+#endif
+    if (ioctl(devfd, SNDCTL_DSP_SAMPLESIZE, &format) < 0) {
 	warn("%s", device);
 	stat = FAIL; goto failplay0;
     }
@@ -121,11 +126,6 @@
 	warn("%s", device);
 	stat = FAIL; goto failplay0;
     }
-    /* XXX */
-    if (ioctl(devfd, SNDCTL_DSP_SETFMT, &format) < 0) {
-	warn("%s", device);
-	stat = FAIL; goto failplay0;
-    }
     if (headerp->channels > 1) {
 	int ch = headerp->channels;
 	if (ioctl(devfd, SNDCTL_DSP_STEREO, &ch) < 0) {
@@ -163,6 +163,8 @@
 	    warn("read");
 	    stat = FAIL; goto failplay2;
 	}
+/*	printf("len = %10d, len = %10d\n", stat, len); */
+	stat = (len < stat)? len : stat;
 	if (write(devfd, bufp, stat) < 0) {
 	    warn("write");
 	    stat = FAIL; goto failplay2;
