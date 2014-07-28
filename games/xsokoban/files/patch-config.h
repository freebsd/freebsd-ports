*** config.h.orig	Tue Aug 27 21:41:47 1996
--- config.h	Mon Nov 18 18:25:14 1996
***************
*** 30,36 ****
  	    variable in the installed version, but you know best...
  */
  #ifndef ROOTDIR
! #define ROOTDIR "."
  #endif
  
  /*
--- 30,36 ----
  	    variable in the installed version, but you know best...
  */
  #ifndef ROOTDIR
! #define ROOTDIR "%%PREFIX%%/lib/X11/xsokoban"
  #endif
  
  /*
***************
*** 95,101 ****
     OWNER: defines the name of the local game owner.
  */
  #ifndef OWNER
! #define OWNER "andru"
  #endif
  
  /*
--- 95,101 ----
     OWNER: defines the name of the local game owner.
  */
  #ifndef OWNER
! #define OWNER "root"
  #endif
  
  /*
***************
*** 147,153 ****
  */
  
  #ifndef WWW
! #define WWW 1
  #endif
  
  #define DEBUG_SERVER(x)
--- 147,153 ----
  */
  
  #ifndef WWW
! #define WWW 0
  #endif
  
  #define DEBUG_SERVER(x)
