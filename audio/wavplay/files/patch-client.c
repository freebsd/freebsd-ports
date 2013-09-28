*** client.c.orig	Sat Jan 15 13:05:07 2000
--- client.c	Sat Jan 15 13:08:42 2000
***************
*** 47,53 ****
--- 47,55 ----
  #include <unistd.h>
  #include <errno.h>
  #include <time.h>
+ #ifndef FREEBSD
  #include <malloc.h>
+ #endif
  #include <string.h>
  #include <memory.h>
  #include <signal.h>
***************
*** 57,63 ****
--- 59,69 ----
  #include <sys/wait.h>
  #include <sys/stat.h>
  #include <assert.h>
+ #ifndef FREEBSD
  #include <linux/soundcard.h>
+ #else
+ #include <sys/soundcard.h>
+ #endif
  #include "wavplay.h"
  #include "client.h"
  
