*** mopt.c.orig	Sat Jun  8 00:25:38 1996
--- mopt.c	Fri May  6 18:24:20 2005
***************
*** 21,27 ****
  #define FAR far
  #define MEMSET _fmemset
  #else
- #include <malloc.h>
  #include <signal.h>
  #define MALLOC malloc
  #define FAR
--- 21,26 ----
