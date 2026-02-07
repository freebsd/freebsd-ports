*** xhime.c.orig	Sun Nov  9 05:45:35 2003
--- xhime.c	Tue Feb  3 22:22:23 2004
***************
*** 24,32 ****
  #include	<signal.h>
  #include	<ctype.h> /* defined in X11/Xos.h ? */
  #include	<string.h>/* defined in X11/Xos.h ? */
  #include	<limits.h>
! #include	<varargs.h>
  #include	<sys/time.h>/* defined in X11/Xos.h */
  #include	<sys/types.h>
  #include	<sys/stat.h>
  #ifndef	O_RDONLY
--- 24,32 ----
  #include	<signal.h>
  #include	<ctype.h> /* defined in X11/Xos.h ? */
  #include	<string.h>/* defined in X11/Xos.h ? */
  #include	<limits.h>
! #include	<stdarg.h>
  #include	<sys/time.h>/* defined in X11/Xos.h */
  #include	<sys/types.h>
  #include	<sys/stat.h>
  #ifndef	O_RDONLY
***************
*** 115,148 ****
  int	ActionFlag = ACT_NONE;
  
  /* -- */
  void
! Error(va_alist)
!      va_dcl
  {
    va_list	args;
-   char	*fmt;
  
    fprintf(stderr, "%s: ", ProgramName);
  
!   va_start(args);
    fmt = (char *)va_arg(args, char *);
    vfprintf(stderr, fmt, args);
    va_end(args);
  
    fprintf(stderr, "\n");
  }
  
  void
! ErrorExit(va_alist)
!      va_dcl
  {
    va_list	args;
-   char	*fmt;
  
    fprintf(stderr, "%s: ", ProgramName);
  
!   va_start(args);
    fmt = (char *)va_arg(args, char *);
    vfprintf(stderr, fmt, args);
    va_end(args);
  
--- 115,144 ----
  int	ActionFlag = ACT_NONE;
  
  /* -- */
  void
! Error(char *fmt, ...)
  {
    va_list	args;
  
    fprintf(stderr, "%s: ", ProgramName);
  
!   va_start(args, fmt);
    fmt = (char *)va_arg(args, char *);
    vfprintf(stderr, fmt, args);
    va_end(args);
  
    fprintf(stderr, "\n");
  }
  
  void
! ErrorExit(char *fmt, ...)
  {
    va_list	args;
  
    fprintf(stderr, "%s: ", ProgramName);
  
!   va_start(args, fmt);
    fmt = (char *)va_arg(args, char *);
    vfprintf(stderr, fmt, args);
    va_end(args);
  
***************
*** 1363,1371 ****
    }
    exit(0);
  }
  
! void
  main(argc, argv)
       int	argc;
       char	*argv[];
  {
--- 1359,1367 ----
    }
    exit(0);
  }
  
! int
  main(argc, argv)
       int	argc;
       char	*argv[];
  {
