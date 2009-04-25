*** scrt/apply.h.orig	Mon Feb 22 11:13:08 1993
--- scrt/apply.h	Sat Mar 14 20:18:50 2009
***************
*** 60,63 ****
  
  extern  TSCP  sc_apply_2dtwo();
  
! extern  TSCP  sc_unknowncall();
--- 60,63 ----
  
  extern  TSCP  sc_apply_2dtwo();
  
! extern  TSCP  sc_unknowncall( TSCP arg0, ... );
