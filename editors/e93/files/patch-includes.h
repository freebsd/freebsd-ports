--- includes.h.orig	2009-08-07 13:50:33 UTC
+++ includes.h
@@ -18,6 +18,7 @@
 
 #include	<stdio.h>
 #include	<stdarg.h>
+#include	<stdbool.h>
 #include	<stdlib.h>
 #include	<errno.h>
 #include	<fcntl.h>
@@ -29,16 +30,6 @@
 #include	<locale.h>
 
 #include	<tcl.h>
-
-// deal with Tcl changing the way this works in newer versions
-#ifndef Tcl_GetErrorLine
-#define	Tcl_GetErrorLine(interpreter)	interpreter->errorLine
-#endif
-
-#ifndef Tcl_GetResult
-#define	Tcl_GetResult(interpreter)		interpreter->result
-#endif
-
 
 #include	"defines.h"
 #include	"guidefs.h"
