*** pcretest.c.orig	Wed Jul  5 21:28:01 2006
--- pcretest.c	Fri Jul  7 19:35:47 2006
***************
*** 45,50 ****
--- 45,51 ----
  #include <errno.h>
  
  #ifndef _WIN32
+ #include <sys/time.h>
  #include <sys/resource.h>
  #endif
  
