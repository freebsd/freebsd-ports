--- party.c.orig	Wed Oct 15 18:28:00 2003
+++ party.c	Wed Oct 15 18:32:29 2003
@@ -82,7 +82,7 @@
 #include <errno.h>
 #include <ctype.h>
 #ifdef VAR_ARGS
-#include <varargs.h>
+#include <stdarg.h>
 #endif /*VAR_ARGS*/
 
 char *version= "2.12";		/* current party version */
@@ -787,23 +787,21 @@
 #endif /*BSD*/
 
 #ifdef VAR_ARGS
-vint db(va_alist)
-va_dcl
+vint db(char *msg, ...)
 {
 va_list ap;
-char *msg;
 long now;
 
     if (debug)
     {
-        va_start(ap);
-        msg= va_arg(ap, char *);
+        va_start(ap, msg);
 
 	now= time((long *)0);
         fprintf(debug,"%8.8s:  ",ctime(&now)+11);
         vfprintf(debug,msg,ap);
 	fflush(debug);
     }
+    va_end(ap);
 }
 #else
 vint db(msg,arg1,arg2,arg3,arg4)
@@ -823,15 +821,12 @@
 
 
 #ifdef VAR_ARGS
-vint err(va_alist)
-va_dcl
+vint err(char *msg, ...)
 {
 va_list ap;
-char *msg;
 long now;
 
-    va_start(ap);
-    msg= va_arg(ap, char *);
+    va_start(ap, msg);
     fprintf(stderr,"%s error: ",progname);
     vfprintf(stderr,msg,ap);
 
@@ -843,6 +838,7 @@
 	vfprintf(debug,msg,ap);
 	fflush(debug);
     }
+    va_end(ap);
 }
 #else
 vint err(msg,arg1,arg2,arg3,arg4)
