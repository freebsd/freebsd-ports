*** config.h.orig	Tue Sep 29 15:15:25 1998
--- config.h	Tue Sep 29 15:24:15 1998
***************
*** 27,31 ****
   * in sys/time.h
   */
! # define	HAVE_SYS_SELECT_H	0
  
  /*
--- 27,31 ----
   * in sys/time.h
   */
! # define	HAVE_SYS_SELECT_H	1
  
  /*
***************
*** 33,37 ****
   * conversion/classification
   */
! # define	HAVE_LOCALE_H		0
  
  /*
--- 33,37 ----
   * conversion/classification
   */
! # define	HAVE_LOCALE_H		1
  
  /*
***************
*** 39,48 ****
   * very weak replacement is used to find matching services
   */
! # define	HAVE_REGEX_H		0
  
  /*
   * one of these is required for SysV like lockfiles
   */
! # define	HAVE_SYS_SYSMACROS_H	1
  # define	HAVE_SYS_MKDEV_H	0
  
--- 39,48 ----
   * very weak replacement is used to find matching services
   */
! # define	HAVE_REGEX_H		1
  
  /*
   * one of these is required for SysV like lockfiles
   */
! # define	HAVE_SYS_SYSMACROS_H	0
  # define	HAVE_SYS_MKDEV_H	0
  
***************
*** 62,72 ****
   * to get valid return values from localtime
   */
! # define	HAVE_TZSET		0
  
  /*
   * If these are not set, chmod()/chown() are used
   */
! # define	HAVE_FCHMOD		0
! # define	HAVE_FCHOWN		0
  
  /*
--- 62,72 ----
   * to get valid return values from localtime
   */
! # define	HAVE_TZSET		1
  
  /*
   * If these are not set, chmod()/chown() are used
   */
! # define	HAVE_FCHMOD		1
! # define	HAVE_FCHOWN		1
  
  /*
***************
*** 74,78 ****
   * longjmp() from the signal handler leads into chaos
   */
! # define	HAVE_SIGSETJMP		0
  
  /*
--- 74,78 ----
   * longjmp() from the signal handler leads into chaos
   */
! # define	HAVE_SIGSETJMP		1
  
  /*
***************
*** 106,110 ****
   * set this to 1, otherwise to 0
   */
! # define	BROKEN_REALLOC		1
  
  /*      -------------- END OF CHANGEABLE PART ------------------	*/
--- 106,110 ----
   * set this to 1, otherwise to 0
   */
! # define	BROKEN_REALLOC		0
  
  /*      -------------- END OF CHANGEABLE PART ------------------	*/
