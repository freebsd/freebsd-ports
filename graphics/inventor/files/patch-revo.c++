*** apps/demos/revo/revo.c++.orig	Fri Jan  3 10:09:04 2003
--- apps/demos/revo/revo.c++	Fri Jan  3 10:11:20 2003
***************
*** 66,71 ****
--- 66,77 ----
  #include "LineManip.h"
  #include "RevClass.h"
  
+ #ifdef __FreeBSD__
+ #define PDF_READER "xpdf"
+ #else
+ #define PDF_READER "acroread"
+ #endif
+ 
  //
  // These are defined in profile.c++
  //
***************
*** 86,102 ****
      }
  
      char command[100];
!     sprintf(command, "which acroread >& /dev/null");
  
      int err = system(command);
      if (err)
      {
! 	system("xmessage 'You must install acroread"
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, "acroread " IVPREFIX "/demos/Inventor/revo.about &");
      system(command);
  }	
  
--- 92,108 ----
      }
  
      char command[100];
!     sprintf(command, "which " PDF_READER " >& /dev/null");
  
      int err = system(command);
      if (err)
      {
! 	system("xmessage 'You must install " PDF_READER
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, PDF_READER " " IVPREFIX "/demos/Inventor/revo.about &");
      system(command);
  }	
  
