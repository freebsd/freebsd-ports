*** ghc/rts/Prelude.h~	Thu Jun 27 16:38:58 2002
--- ghc/rts/Prelude.h	Fri Jul 19 11:20:52 2002
***************
*** 14,32 ****
   * modules these names are defined in.
   */
  
! extern DLL_IMPORT const StgClosure GHCziBase_True_closure;
! extern DLL_IMPORT const StgClosure GHCziBase_False_closure;
! extern DLL_IMPORT const StgClosure GHCziPack_unpackCString_closure;
! extern DLL_IMPORT const StgClosure GHCziWeak_runFinalizzerBatch_closure;
! extern const StgClosure Main_zdmain_closure;
! extern DLL_IMPORT const StgClosure GHCziTopHandler_runIO_closure;
! extern DLL_IMPORT const StgClosure GHCziTopHandler_runNonIO_closure;
  
! extern DLL_IMPORT const StgClosure GHCziIOBase_stackOverflow_closure;
! extern DLL_IMPORT const StgClosure GHCziIOBase_heapOverflow_closure;
! extern DLL_IMPORT const StgClosure GHCziIOBase_BlockedOnDeadMVar_closure;
! extern DLL_IMPORT const StgClosure GHCziIOBase_NonTermination_closure;
! extern DLL_IMPORT const StgClosure GHCziIOBase_Deadlock_closure;
  
  extern DLL_IMPORT const StgInfoTable GHCziBase_Czh_static_info;
  extern DLL_IMPORT const StgInfoTable GHCziBase_Izh_static_info;
--- 14,32 ----
   * modules these names are defined in.
   */
  
! extern DLL_IMPORT StgClosure GHCziBase_True_closure;
! extern DLL_IMPORT StgClosure GHCziBase_False_closure;
! extern DLL_IMPORT StgClosure GHCziPack_unpackCString_closure;
! extern DLL_IMPORT StgClosure GHCziWeak_runFinalizzerBatch_closure;
! extern StgClosure Main_zdmain_closure;
! extern DLL_IMPORT StgClosure GHCziTopHandler_runIO_closure;
! extern DLL_IMPORT StgClosure GHCziTopHandler_runNonIO_closure;
  
! extern DLL_IMPORT StgClosure GHCziIOBase_stackOverflow_closure;
! extern DLL_IMPORT StgClosure GHCziIOBase_heapOverflow_closure;
! extern DLL_IMPORT StgClosure GHCziIOBase_BlockedOnDeadMVar_closure;
! extern DLL_IMPORT StgClosure GHCziIOBase_NonTermination_closure;
! extern DLL_IMPORT StgClosure GHCziIOBase_Deadlock_closure;
  
  extern DLL_IMPORT const StgInfoTable GHCziBase_Czh_static_info;
  extern DLL_IMPORT const StgInfoTable GHCziBase_Izh_static_info;
