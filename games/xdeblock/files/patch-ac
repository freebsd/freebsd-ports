*** dialog.c.orig	Sat Nov 16 14:37:15 1996
--- dialog.c	Fri Jan 15 00:00:00 2000
***************
*** 8,14 ****
  
  #include        <sys/types.h>
  #include        <sys/stat.h>
! #include        <sys/dir.h>
  
  #include 	"gameheader.h"
  
--- 8,14 ----
  
  #include        <sys/types.h>
  #include        <sys/stat.h>
! #include        <dirent.h>
  
  #include 	"gameheader.h"
  
***************
*** 430,436 ****
       char    *fflag;
  {
    DIR           *dp;
!   struct direct *dir;
    struct stat   sbuf;
    char          newname[256];
    register      i = 0;
--- 430,436 ----
       char    *fflag;
  {
    DIR           *dp;
!   struct dirent *dir;
    struct stat   sbuf;
    char          newname[256];
    register      i = 0;
