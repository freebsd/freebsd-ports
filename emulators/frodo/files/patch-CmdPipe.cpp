*** CmdPipe.cpp	Wed Aug  6 20:56:26 1997
--- CmdPipe.cpp.neu	Fri Sep  5 14:15:37 1997
***************
*** 29,34 ****
--- 29,37 ----
  #if defined(__linux__)
  	#include <sys/time.h>
  #endif
+ #if defined(__FreeBSD__)
+ 	#include <sys/time.h>
+ #endif
  
  	#include <time.h>
  	#include <errno.h>
