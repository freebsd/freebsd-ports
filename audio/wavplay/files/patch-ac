*** file.c.orig	Sat Jan 15 12:55:46 2000
--- file.c	Sat Jan 15 13:15:38 2000
***************
*** 56,62 ****
--- 56,64 ----
  #include <unistd.h>
  #include <errno.h>
  #include <fcntl.h>
+ #ifndef FREEBSD
  #include <malloc.h>
+ #endif
  #include <string.h>
  #include <memory.h>
  #include <signal.h>
***************
*** 64,70 ****
--- 66,76 ----
  #include <sys/ipc.h>
  #include <sys/ioctl.h>
  #include <assert.h>
+ #ifndef FREEBSD
  #include <linux/soundcard.h>
+ #else
+ #include <sys/soundcard.h>
+ #endif
  #include "wavplay.h"
  
  extern int clntIPC;    /* Needed for message passing in PlayDSP */
