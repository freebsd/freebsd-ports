*** tleap/database.c.orig	Wed Mar 27 15:41:01 2002
--- tleap/database.c	Sun Jun  2 12:59:14 2002
***************
*** 97,102 ****
--- 97,109 ----
  
  
  
+ #if (defined(__unix__) || defined(unix)) && !defined(USG)
+ #include <sys/param.h>
+ #endif
+ 
+ #if defined(BSD)
+ #include <math.h>
+ #endif
  
  
  #include	"basics.h"
***************
*** 563,569 ****
  
      sRemoveLeadingSpaces( sLine );
      sRemoveFirstString( sLine, sHead );
! #ifdef linux
      sscanf( sHead, "%lg", dPDbl );
  #else
      sscanf( sHead, "%lG", dPDbl );
--- 570,576 ----
  
      sRemoveLeadingSpaces( sLine );
      sRemoveFirstString( sLine, sHead );
! #if defined(linux) || defined(BSD)
      sscanf( sHead, "%lg", dPDbl );
  #else
      sscanf( sHead, "%lG", dPDbl );
