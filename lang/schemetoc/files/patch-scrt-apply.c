*** scrt/apply.c.orig	Mon Feb 22 11:10:06 1993
--- scrt/apply.c	Sat Mar 14 21:49:29 2009
***************
*** 50,56 ****
  #include "scinit.h"
  #include "heap.h"
  #include "apply.h"
! #include <varargs.h>
  
  /* Data structures used by UNKNOWNCALL.  These values must be pushed on the
     stack and then restored by interrupt handlers or when calling finalization
--- 50,56 ----
  #include "scinit.h"
  #include "heap.h"
  #include "apply.h"
! #include <stdarg.h>
  
  /* Data structures used by UNKNOWNCALL.  These values must be pushed on the
     stack and then restored by interrupt handlers or when calling finalization
***************
*** 283,290 ****
     in the call, or the procedure takes a variable number of arguments.
  */
  
! TSCP  sc_unknowncall( va_alist )
!    va_dcl
  {
  	va_list  argl;			/* List of arguments on stack */
  	int  req;			/* # of required arguments */
--- 283,289 ----
     in the call, or the procedure takes a variable number of arguments.
  */
  
! TSCP  sc_unknowncall( TSCP arg0, ... )
  {
  	va_list  argl;			/* List of arguments on stack */
  	int  req;			/* # of required arguments */
***************
*** 293,299 ****
  	TSCP  tail;			/* Tail of optional argument list */
  	SCP  utproc;			/* Untagged version of proc */
  
! 	va_start( argl );
  	utproc = T_U( sc_unknownproc[ 1 ] );
          if ((TSCPTAG( sc_unknownproc[ 1 ] ) != EXTENDEDTAG) ||
              (utproc->procedure.tag != PROCEDURETAG))
--- 292,298 ----
  	TSCP  tail;			/* Tail of optional argument list */
  	SCP  utproc;			/* Untagged version of proc */
  
! 	va_start( argl, arg0 );
  	utproc = T_U( sc_unknownproc[ 1 ] );
          if ((TSCPTAG( sc_unknownproc[ 1 ] ) != EXTENDEDTAG) ||
              (utproc->procedure.tag != PROCEDURETAG))
***************
*** 304,313 ****
  	     ((utproc->procedure.optional == 0) && (sc_unknownargc != req)))
  	   sc_error( "APPLY", "PROCEDURE requires ~s arguments, ~s supplied",
  		      LIST2( C_FIXED( req ), C_FIXED( sc_unknownargc ) ) );
! 	for  (i = 0; i < req; i++)  sc_arg[ i ] = va_arg( argl, TSCP );
  	optl = EMPTYLIST;
! 	if  (i++ < sc_unknownargc)  {
! 	   tail = (optl = sc_cons( va_arg( argl, TSCP ), EMPTYLIST ));
  	   while  (i++ < sc_unknownargc)
  	      tail = (TP_U( tail )->pair.cdr = sc_cons( va_arg( argl, TSCP ),
  							EMPTYLIST ));
--- 303,313 ----
  	     ((utproc->procedure.optional == 0) && (sc_unknownargc != req)))
  	   sc_error( "APPLY", "PROCEDURE requires ~s arguments, ~s supplied",
  		      LIST2( C_FIXED( req ), C_FIXED( sc_unknownargc ) ) );
! 	for  (i = 0; i < req; i++)  sc_arg[ i ] = !i ? arg0 : va_arg( argl, TSCP );
  	optl = EMPTYLIST;
! 	if  (i < sc_unknownargc)  {
! 	   tail = (optl = sc_cons( !i ? arg0 : va_arg( argl, TSCP ), EMPTYLIST ));
! 	   ++i;
  	   while  (i++ < sc_unknownargc)
  	      tail = (TP_U( tail )->pair.cdr = sc_cons( va_arg( argl, TSCP ),
  							EMPTYLIST ));
