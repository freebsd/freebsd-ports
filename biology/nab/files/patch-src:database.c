*** src/database.c.orig	Wed Nov 15 19:46:50 2000
--- src/database.c	Sun Jun  2 12:57:50 2002
***************
*** 67,72 ****
--- 67,79 ----
  
  
  
+ #if (defined(__unix__) || defined(unix)) && !defined(USG)
+ #include <sys/param.h>
+ #endif
+ 
+ #if defined(BSD)
+ #include <math.h>
+ #endif
  
  
  #include	"stdio.h"
***************
*** 979,985 ****
--- 986,996 ----
  
      sDBRemoveLeadingSpaces( sLine );
      sDBRemoveFirstString( sLine, sHead );
+ #if defined (linux) || defined(BSD)
+     sscanf( sHead, "%lg", dPDbl );
+ #else
      sscanf( sHead, "%lG", dPDbl );
+ #endif
  
  }
  
