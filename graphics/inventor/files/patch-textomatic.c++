*** apps/demos/textomatic/textomatic.c++.orig	Fri Jan  3 10:12:24 2003
--- apps/demos/textomatic/textomatic.c++	Fri Jan  3 10:13:33 2003
***************
*** 69,74 ****
--- 69,80 ----
  #include "../../samples/common/Useful.h"
  #include "./labels.h"
  
+ #ifdef __FreeBSD__
+ #define PDF_READER "xpdf"
+ #else
+ #define PDF_READER "acroread"
+ #endif
+ 
  //
  // Some evil variables global to this file.  I should pass them around
  // as paramaters or encapsulate them in a class, but this is easier.
***************
*** 164,179 ****
      }
  
      char command[100];
!     sprintf(command, "which acroread > /dev/null");
  
      int err = system(command);
      if (err) {
! 	system("xmessage 'You must install acroread"
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, "acroread " IVPREFIX "/demos/Inventor/textomatic.about &");
      system(command);
  }	
  
--- 170,186 ----
      }
  
      char command[100];
!     sprintf(command, "which " PDF_READER "> /dev/null");
  
      int err = system(command);
      if (err) {
! 	system("xmessage 'You must install " PDF_READER
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, PDF_READER " "
!             IVPREFIX "/demos/Inventor/textomatic.about &");
      system(command);
  }	
  
