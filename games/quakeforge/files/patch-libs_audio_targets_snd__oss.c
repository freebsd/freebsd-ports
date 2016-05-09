--- libs/audio/targets/snd_oss.c.orig	2013-01-23 03:10:55 UTC
+++ libs/audio/targets/snd_oss.c
@@ -129,12 +129,11 @@ try_open (int rw)
 	if (snd_device->string[0])
 		snd_dev = snd_device->string;
 
-	if (rw) {
+	if (rw)
 		omode = O_RDWR;
-		mmmode |= PROT_READ;
-		mmflags |= MAP_SHARED;
-	}
 	omode |= O_NONBLOCK;
+	mmmode |= PROT_READ;
+	mmflags |= MAP_SHARED;	/* device mmapping on FreeBSD requires this */
 
 	audio_fd = open (snd_dev, omode);
 	if (audio_fd < 0) {					// Failed open, retry up to 3 times
