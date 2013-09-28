*** msg.c.orig	Sat Jan 15 12:58:40 2000
--- msg.c	Sat Jan 15 13:16:12 2000
***************
*** 47,53 ****
--- 47,55 ----
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
*** 56,62 ****
--- 58,68 ----
  #include <sys/msg.h>
  #include <sys/ioctl.h>
  #include <assert.h>
+ #ifndef FREEBSD
  #include <linux/soundcard.h>
+ #else
+ #include <sys/soundcard.h>
+ #endif
  #include "wavplay.h"
  
  /*
