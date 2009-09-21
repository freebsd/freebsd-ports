--- ./devp/devposs.c.orig	2009-09-21 14:23:33.000000000 +0200
+++ ./devp/devposs.c	2009-09-21 14:25:24.000000000 +0200
@@ -448,6 +448,7 @@
 	if (fcntl(fd_dsp, F_SETFD, FD_CLOEXEC)<0)
 		perror("devposs: fcntl(fd_dsp, F_SETFD, FD_CLOEXEC)");
 #ifdef OSS_DEBUG
+/*
  #if defined(OSS_GETVERSION)
 	if (ioctl(fd_dsp, OSS_GETVERSION, &tmp)<0)
 		tmp=0;
@@ -458,6 +459,7 @@
  #elif defined(SOUND_VERSION)
 	fprintf(stderr, "devposs: compiled agains OSS version %d.%d.%d\n", (SOUND_VERSION&0xff0000)>>16, (SOUND_VERSION&0xff00)>>8, SOUND_VERSION&0xff);
  #endif
+*/
 #endif
 	plrSetOptions(plrRate, plrOpt);
 
@@ -597,6 +599,7 @@
 		return 0;
 	}
 
+/*
 #if defined(OSS_GETVERSION)
 	if (ioctl(fd_dsp, OSS_GETVERSION, &tmp)<0)
 	{
@@ -607,6 +610,7 @@
 		return 0;
 	}
 #endif
+*/
 
 #ifdef OSS_DEBUG
 	fprintf(stderr, "devposs: OSS detected\n");
