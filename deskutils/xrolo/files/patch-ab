*** main.c.org	Sat Jan  9 22:25:04 1999
--- main.c	Sat Jan  9 22:26:03 1999
***************
*** 39,45 ****
  #include <sys/param.h>
  #include <stdio.h>
  #include <sys/types.h>
! #include <sys/dir.h>
  #include <xview/xview.h>
  #include <xview/panel.h>
  #include <xview/textsw.h>
--- 39,45 ----
  #include <sys/param.h>
  #include <stdio.h>
  #include <sys/types.h>
! #include <sys/dirent.h>
  #include <xview/xview.h>
  #include <xview/panel.h>
  #include <xview/textsw.h>
***************
*** 65,72 ****
  
  extern void		init_rolo ();
  
! extern char		*check_args (), *getenv (), *strcpy (),
! 			*calloc (), *malloc ();
  
  extern char             *exp_fname();
  
--- 65,72 ----
  
  extern void		init_rolo ();
  
! extern char		*check_args (), *getenv (), *strcpy ();/*,
! 			*calloc (), *malloc ();*/
  
  extern char             *exp_fname();
  
***************
*** 320,323 ****
  
  	return (strcpy (q, p));
  }
- 
--- 320,322 ----
