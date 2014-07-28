*** externs.h.orig	Sun Apr 16 07:46:14 1995
--- externs.h	Sat Jan 15 00:00:00 2000
***************
*** 5,11 ****
--- 5,13 ----
  #include <X11/Xresource.h>
  #include <sys/stat.h>
  #include <sys/types.h>
+ #ifndef __STDC__
  #include <malloc.h>
+ #endif
  
  #ifdef NEED_NETINET_IN
  #include <netinet/in.h>
