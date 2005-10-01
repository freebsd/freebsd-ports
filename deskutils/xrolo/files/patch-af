*** popup.c.orig	Tue Dec  3 23:28:39 1991
--- popup.c	Sat Oct  1 20:06:23 2005
***************
*** 6,11 ****
--- 6,14 ----
   *	popup - pop up error dialog windows
   */
  
+ #if (defined(__unix__) || defined(unix)) && !defined(USG)
+ #include <sys/param.h>
+ #endif
  
  #include <xview/xview.h>
  #include <xview/panel.h>
***************
*** 26,32 ****
  
  /* ---------------------------- Imports -------------------------------- */
  
! #if !defined(sgi)
  extern char		*sprintf ();
  #endif
  
--- 29,35 ----
  
  /* ---------------------------- Imports -------------------------------- */
  
! #if !defined(sgi) && !(defined(BSD) && (BSD >= 199306))
  extern char		*sprintf ();
  #endif
  
***************
*** 92,95 ****
  	(void) sprintf (temp, s, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
  	return (do_pop (frame, temp, FALSE));
  }
- 
--- 95,97 ----
