--- reg.y.org	Mon Nov 29 18:43:56 1993
+++ reg.y	Thu Jan 20 12:29:44 2005
@@ -20,6 +20,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include "cmt.h"
 #include "euc.h"
@@ -286,7 +287,7 @@
  *  Node Creation Functions                                           *
  *                                                                    *
  **********************************************************************/
-extern void error();
+extern void error(char *, ...);
 
 /*---------------------------------------------------------------------
     NAME
