*** cards.c.orig	Tue Dec  3 23:33:56 1991
--- cards.c	Sat Oct  1 20:07:14 2005
***************
*** 36,47 ****
   */
  
  
  
  #include <stdio.h>
  #include <xview/xview.h>
  #include <sys/file.h>
  #include <ctype.h>
! #if !defined(sgi)
  #include <alloca.h>
  #endif
  #include <pwd.h>
--- 36,56 ----
   */
  
  
+ #if (defined(__unix__) || defined(unix)) && !defined(USG)
+ #include <sys/param.h>
+ #endif
+ 
+ #if (defined(BSD) && (BSD >= 199306))
+ #include <stdlib.h>
+ #include <strings.h>
+ #include <errno.h>
+ #endif
  
  #include <stdio.h>
  #include <xview/xview.h>
  #include <sys/file.h>
  #include <ctype.h>
! #if !defined(sgi) && !(defined(BSD) && (BSD >= 199306))
  #include <alloca.h>
  #endif
  #include <pwd.h>
***************
*** 71,85 ****
  
  extern void		show_card (), set_slider_max ();
  
  extern char		*malloc(), *realloc (), *calloc (), *getenv();
  #if !defined(sgi)
  extern char 		*strcpy(), *strcat(), *strncpy (), *index ();
  #endif
  extern char		*sys_errlist [];
  
  extern int		errno;
  
- 
  /* --------------------------- Locals -------------------------------------- */
  
  static struct card	*dead;
--- 80,95 ----
  
  extern void		show_card (), set_slider_max ();
  
+ #if !(defined (BSD) && (BSD >= 199306))
  extern char		*malloc(), *realloc (), *calloc (), *getenv();
  #if !defined(sgi)
  extern char 		*strcpy(), *strcat(), *strncpy (), *index ();
  #endif
  extern char		*sys_errlist [];
+ #endif
  
  extern int		errno;
  
  /* --------------------------- Locals -------------------------------------- */
  
  static struct card	*dead;
***************
*** 757,763 ****
  char *s1, *s2;
  {
  	int retval;
! 	char *p1, *alloca();
  	char *p2;
  
  	if ( *s2 == '\0' && *s1 == '\0') 
--- 767,773 ----
  char *s1, *s2;
  {
  	int retval;
! 	char *p1;
  	char *p2;
  
  	if ( *s2 == '\0' && *s1 == '\0')
