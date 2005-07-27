*** base/src/TMath.cxx.orig	Mon Jun 13 15:31:57 2005
--- base/src/TMath.cxx	Sat Jul  9 19:38:38 2005
***************
*** 31,37 ****
  const Int_t kWorkMax = 100;
  
  // Without this macro the THtml doc for TMath can not be generated
! #if !defined(R__ALPHA) && !defined(R__SOLARIS) && !defined(R__ACC)
  NamespaceImp(TMath)
  #endif
  
--- 31,37 ----
  const Int_t kWorkMax = 100;
  
  // Without this macro the THtml doc for TMath can not be generated
! #if !defined(R__ALPHA) && !defined(R__SOLARIS) && !defined(R__ACC) && !defined(R__FBSD)
  NamespaceImp(TMath)
  #endif
  
