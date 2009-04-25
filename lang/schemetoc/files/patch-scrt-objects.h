*** scrt/objects.h.orig	Tue Feb 23 18:29:09 1993
--- scrt/objects.h	Sat Mar 14 20:21:00 2009
***************
*** 798,804 ****
  extern TSCP   sc_makeclosure(...);
  extern TSCP   sc_makeprocedure(...);
  #else
! extern TSCP   sc_makeclosure();
  extern TSCP   sc_makeprocedure();
  #endif
  
--- 798,804 ----
  extern TSCP   sc_makeclosure(...);
  extern TSCP   sc_makeprocedure(...);
  #else
! extern TSCP   sc_makeclosure( TSCP prevclosure, ... );
  extern TSCP   sc_makeprocedure();
  #endif
  
