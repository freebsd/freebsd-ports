*** apps/demos/SceneViewer/SoSceneViewer.c++.orig	Fri Jan  3 09:59:15 2003
--- apps/demos/SceneViewer/SoSceneViewer.c++	Fri Jan  3 10:01:02 2003
***************
*** 141,146 ****
--- 141,151 ----
  #include <assert.h>
  #endif
   
+ #ifdef __FreeBSD__
+ #define PDF_READER	"xpdf"
+ #else
+ #define PDF_READER	"acroread"
+ #endif
  
  //
  //  Macros and constants
***************
*** 4739,4755 ****
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
  
!     sprintf(command, "acroread "
              IVPREFIX "/demos/Inventor/SceneViewer.about &");
      system(command);
  }
--- 4744,4760 ----
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
  
!     sprintf(command, PDF_READER " "
              IVPREFIX "/demos/Inventor/SceneViewer.about &");
      system(command);
  }
