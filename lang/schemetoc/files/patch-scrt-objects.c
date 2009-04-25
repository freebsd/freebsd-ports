*** scrt/objects.c.orig	Mon Feb 22 11:12:04 1993
--- scrt/objects.c	Sat Mar 14 20:28:00 2009
***************
*** 48,54 ****
  #include "heap.h"
  #include "apply.h"
  #include "cio.h"
! #include <varargs.h>
  
  #ifndef NULL
  #define NULL 0
--- 48,54 ----
  #include "heap.h"
  #include "apply.h"
  #include "cio.h"
! #include <stdarg.h>
  
  #ifndef NULL
  #define NULL 0
***************
*** 293,310 ****
     allocate variables and is visible within the compiler as MAKECLOSURE.
  */
  
! TSCP sc_makeclosure( va_alist )
! 	va_dcl
  {
  	va_list  argl;
- 	TSCP prevclosure;
  	int  count;
  	SCP  cp;
  	PATSCP  vars;
  
  	MUTEXON;
! 	va_start( argl );
! 	prevclosure = va_arg( argl, TSCP );
  	count = va_arg( argl, int );
  	cp = sc_allocateheap( CLOSURESIZE( count ), CLOSURETAG, count );
  	cp->closure.closure = prevclosure;
--- 293,307 ----
     allocate variables and is visible within the compiler as MAKECLOSURE.
  */
  
! TSCP sc_makeclosure( TSCP prevclosure, ... )
  {
  	va_list  argl;
  	int  count;
  	SCP  cp;
  	PATSCP  vars;
  
  	MUTEXON;
! 	va_start( argl, prevclosure );
  	count = va_arg( argl, int );
  	cp = sc_allocateheap( CLOSURESIZE( count ), CLOSURETAG, count );
  	cp->closure.closure = prevclosure;
