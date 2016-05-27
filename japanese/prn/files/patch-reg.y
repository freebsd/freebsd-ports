--- reg.y.orig	1993-11-29 09:43:56 UTC
+++ reg.y
@@ -20,6 +20,7 @@ static char *sccsid = "@(#)reg.y 2.1 (Y.
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include "cmt.h"
 #include "euc.h"
@@ -286,7 +287,7 @@ yyerror(s)
  *  Node Creation Functions                                           *
  *                                                                    *
  **********************************************************************/
-extern void error();
+extern void error(char *, ...);
 
 /*---------------------------------------------------------------------
     NAME
