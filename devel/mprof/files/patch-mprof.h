*** ../m/mprof.h	Tue Apr 20 13:36:07 1993
--- mprof.h	Fri Sep 17 16:53:52 1993
***************
*** 109,115 ****
  
  extern	char	*strdup();
  
! #if (defined(vax) || (defined(sun) && !defined(sun4)))
  #define get_current_fp(first_local) ((unsigned)&(first_local) + 4)
  #endif
  
--- 109,115 ----
  
  extern	char	*strdup();
  
! #if (defined(vax) || (defined(sun) && !defined(sun4))) || defined(__FreeBSD__)
  #define get_current_fp(first_local) ((unsigned)&(first_local) + 4)
  #endif
  
***************
*** 120,126 ****
  #define ret_addr_from_fp(fp)	(unsigned)(((struct frame *)(fp))->fr_savpc)
  #endif
  
!   
  /* for ultrix 0x38, 4.3 bsd 0x3d, other?
  */
    
--- 120,130 ----
  #define ret_addr_from_fp(fp)	(unsigned)(((struct frame *)(fp))->fr_savpc)
  #endif
  
! #if defined(__FreeBSD__)
! #define prev_fp_from_fp(fp)	*((unsigned *) fp)
! #define ret_addr_from_fp(fp)	*((unsigned *) (fp+4))
! #endif
! 
  /* for ultrix 0x38, 4.3 bsd 0x3d, other?
  */
    
***************
*** 134,137 ****
--- 138,145 ----
  
  #ifdef mips
  #define CRT0_ADDRESS		0x0  /* to be filled in later */
+ #endif
+ 
+ #ifdef __FreeBSD__
+ #define CRT0_ADDRESS		0x10d3
  #endif
