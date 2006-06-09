*** waveplay.c~	Mon Sep 24 16:38:40 2001
--- waveplay.c	Thu Jun  8 00:22:50 2006
***************
*** 286,293 ****
      int status;
      int arg;
  
!     if ((fd = open(devname, O_WRONLY)) == -1)
      	return fd;
  
      /* チャンネル(STEREO or MONAURAL)を設定 */
      arg = (int)(pwf->nChannels);
--- 286,296 ----
      int status;
      int arg;
  
!     if ((fd = open(devname, O_WRONLY)) == -1) {
!         fprintf(stderr, "%s - ", devname);
!         perror("openDSP");
      	return fd;
+     }
  
      /* チャンネル(STEREO or MONAURAL)を設定 */
      arg = (int)(pwf->nChannels);
