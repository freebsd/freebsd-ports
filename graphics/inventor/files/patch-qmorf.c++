*** apps/demos/qmorf/qmorf.c++.orig	Fri Jan  3 10:06:23 2003
--- apps/demos/qmorf/qmorf.c++	Fri Jan  3 10:07:59 2003
***************
*** 81,86 ****
--- 81,92 ----
  #include <Xm/PushBG.h>
  #include <Xm/ToggleBG.h>
  
+ #ifdef __FreeBSD__
+ #define PDF_READER "xpdf"
+ #else
+ #define PDF_READER "acroread"
+ #endif
+ 
  //
  // The list of things we'll morph between
  //
***************
*** 443,459 ****
  	return;
      }
      char command[100];
!     sprintf(command, "which acroread > /dev/null");
  
      int err = system(command);
      if (err)
      {
! 	system("xmessage 'You must install acroread"
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, "acroread " IVPREFIX "/demos/Inventor/qmorf.about &");
      system(command);
  }	
  
--- 449,465 ----
  	return;
      }
      char command[100];
!     sprintf(command, "which " PDF_READER " > /dev/null");
  
      int err = system(command);
      if (err)
      {
! 	system("xmessage 'You must install " PDF_READER
  	       " for this function to work' > /dev/null");
  	return;
      }
  
!     sprintf(command, PDF_READER " " IVPREFIX "/demos/Inventor/qmorf.about &");
      system(command);
  }	
  
