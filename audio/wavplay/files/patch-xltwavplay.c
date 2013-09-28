*** xltwavplay.c.orig	Sat Jan 15 13:12:38 2000
--- xltwavplay.c	Sat Jan 15 13:13:02 2000
***************
*** 59,65 ****
--- 59,67 ----
  #include <time.h>
  #include <signal.h>
  #include <string.h>
+ #ifndef FREEBSD
  #include <getopt.h>
+ #endif
  #include <errno.h>
  #include <sys/types.h>
  #include <sys/ipc.h>
