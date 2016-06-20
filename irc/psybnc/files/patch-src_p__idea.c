--- src/p_idea.c.orig	2016-06-20 14:41:27 UTC
+++ src/p_idea.c
@@ -50,6 +50,9 @@ static char rcsid[] = "@(#)$Id: p_idea.c
  * string encryption by psychoid
  */
 
+
+#include <p_global.h>
+/*
 #include <time.h>
 #include <string.h>
 #include <stdlib.h>
@@ -62,7 +65,7 @@ extern int cline;
 
 #define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt));strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
 #define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
-
+*/
 #ifdef CRYPT
 
 #define IDEAROUNDS 8
