--- echolinux/vox.c.orig	Tue Feb  3 01:12:09 2004
+++ echolinux/vox.c	Fri Jul  2 00:58:47 2004
@@ -546,7 +546,7 @@
 	timeout.tv_sec = 1;
 	timeout.tv_usec = 0;
 	for(i=0;i<4;i++){
-	  temp = &(voicePacket->data);
+	  temp = (unsigned char *)&(voicePacket->data);
 	  gsm_decode(gsmh, temp+(i*33), sbuff);
 	  ioctl(audiofd, SNDCTL_DSP_GETOSPACE, &info);
 	  while(info.bytes < 320){
