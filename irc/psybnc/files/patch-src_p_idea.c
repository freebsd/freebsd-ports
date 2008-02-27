diff -urN src/p_idea.c psybnc.new/src/p_idea.c
--- src/p_idea.c	2005-06-04 22:22:45.000000000 +0400
+++ src/p_idea.c	2008-02-25 23:44:12.000000000 +0300
@@ -50,6 +50,9 @@
  * string encryption by psychoid
  */
 
+
+#include <p_global.h>
+/*
 #include <time.h>
 #include <string.h>
 #include <stdlib.h>
@@ -62,7 +65,7 @@
 
 #define pcontext { strmncpy(ctxt,__FILE__,sizeof(ctxt));strmncpy(cfunc,__FUNCTION__,sizeof(cfunc)); cline=__LINE__; }
 #define pmalloc(n) __pmalloc((n),__FILE__,__FUNCTION__,__LINE__)
-
+*/
 #ifdef CRYPT
 
 #define IDEAROUNDS 8
