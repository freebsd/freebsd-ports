*** make/common.mak.orig	Tue Jul 29 11:25:23 2003
--- make/common.mak	Wed Jun  8 16:50:19 2005
***************
*** 262,268 ****
  endif
  
  ifneq ($(P_SHAREDLIB),1)
! LDFLAGS += -static
  endif
  
  #  clean whitespace out of source file list
--- 262,268 ----
  endif
  
  ifneq ($(P_SHAREDLIB),1)
! #LDFLAGS += -static
  endif
  
  #  clean whitespace out of source file list
