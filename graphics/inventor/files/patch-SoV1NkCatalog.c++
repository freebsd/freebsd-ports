*** lib/nodekits/src/upgraders/SoV1NkCatalog.c++.orig	Thu Jan  2 20:19:39 2003
--- lib/nodekits/src/upgraders/SoV1NkCatalog.c++	Thu Jan  2 20:20:07 2003
***************
*** 51,56 ****
--- 51,59 ----
   _______________________________________________________________________
   */
  
+ #ifdef __FreeBSD__
+ #include <stdlib.h>
+ #endif
  
  #include <Inventor/misc/upgraders/SoV1NodekitCatalog.h>
  #include <Inventor/SoDB.h>
