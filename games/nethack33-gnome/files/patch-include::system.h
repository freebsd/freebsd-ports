*** include/system.h.orig	Thu Jan  6 11:20:08 2000
--- include/system.h	Sat Sep 23 01:08:09 2000
***************
*** 516,522 ****
  # if defined(ULTRIX) || defined(SYSV) || defined(MICRO) || defined(VMS) || defined(MAC) || (defined(HPUX) && defined(_POSIX_SOURCE))
  E time_t FDECL(time, (time_t *));
  # else
! E long FDECL(time, (time_t *));
  # endif /* ULTRIX */
  
  #ifdef VMS
--- 516,522 ----
  # if defined(ULTRIX) || defined(SYSV) || defined(MICRO) || defined(VMS) || defined(MAC) || (defined(HPUX) && defined(_POSIX_SOURCE))
  E time_t FDECL(time, (time_t *));
  # else
! E time_t FDECL(time, (time_t *));
  # endif /* ULTRIX */
  
  #ifdef VMS
