*** ghc/includes/RtsAPI.h~	Thu Jun 27 16:38:58 2002
--- ghc/includes/RtsAPI.h	Fri Jul 19 11:19:38 2002
***************
*** 122,129 ****
     These are used by foreign export and foreign import "wrapper" stubs.
     ----------------------------------------------------------------------- */
  
! extern DLL_IMPORT const StgClosure GHCziTopHandler_runIO_closure;
! extern DLL_IMPORT const StgClosure GHCziTopHandler_runNonIO_closure;
  #define runIO_closure		  (&GHCziTopHandler_runIO_closure)
  #define runNonIO_closure	  (&GHCziTopHandler_runNonIO_closure)
  
--- 122,129 ----
     These are used by foreign export and foreign import "wrapper" stubs.
     ----------------------------------------------------------------------- */
  
! extern StgClosure GHCziTopHandler_runIO_closure;
! extern StgClosure GHCziTopHandler_runNonIO_closure;
  #define runIO_closure		  (&GHCziTopHandler_runIO_closure)
  #define runNonIO_closure	  (&GHCziTopHandler_runNonIO_closure)
  
