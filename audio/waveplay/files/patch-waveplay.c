--- waveplay.c.orig	2001-09-24 07:38:40 UTC
+++ waveplay.c
@@ -286,8 +286,11 @@ int openDSP(const char* devname, PWAVEFO
     int status;
     int arg;
 
-    if ((fd = open(devname, O_WRONLY)) == -1)
+    if ((fd = open(devname, O_WRONLY)) == -1) {
+        fprintf(stderr, "%s - ", devname);
+        perror("openDSP");
     	return fd;
+    }
 
     /* チャンネル(STEREO or MONAURAL)を設定 */
     arg = (int)(pwf->nChannels);
