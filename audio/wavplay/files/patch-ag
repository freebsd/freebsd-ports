*** server.c.orig	Sat Jan 15 12:59:19 2000
--- server.c	Sat Jan 15 13:17:07 2000
***************
*** 65,71 ****
--- 65,73 ----
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
*** 79,85 ****
--- 81,91 ----
  #ifdef SCHED_PRIORITY
  #include <sched.h>
  #endif
+ #ifndef FREEBSD
  #include <linux/soundcard.h>
+ #else
+ #include <sys/soundcard.h>
+ #endif
  #include "wavplay.h"
  #include "server.h"
  
