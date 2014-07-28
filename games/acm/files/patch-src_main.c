*** src/main.c~	Wed Dec 23 23:29:00 1998
--- src/main.c	Mon Feb  1 19:14:05 1999
***************
*** 444,448 ****
  #endif
  
! 	init(".");
  
  	dpy = XOpenDisplay(display);
--- 444,451 ----
  #endif
  
! #ifndef ACM_LIBRARY
! #define ACM_LIBRARY "."
! #endif
! 	init(ACM_LIBRARY "/");
  
  	dpy = XOpenDisplay(display);
