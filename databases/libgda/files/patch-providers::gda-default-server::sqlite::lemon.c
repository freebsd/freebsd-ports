--- providers/gda-default-server/sqlite/lemon.c.orig	Mon Aug  4 09:34:14 2003
+++ providers/gda-default-server/sqlite/lemon.c	Mon Aug  4 09:43:12 2003
@@ -7,7 +7,7 @@
 ** The author of this program disclaims copyright.
 */
 #include <stdio.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include <string.h>
 #include <ctype.h>
 
@@ -70,7 +70,7 @@
 void Configlist_reset(/* void */);
 
 /********* From the file "error.h" ***************************************/
-void ErrorMsg( /* char *, int, char *, ... */ );
+void ErrorMsg( char *, int, char *, ... );
 
 /****** From the file "option.h" ******************************************/
 struct s_options {
@@ -1092,12 +1092,13 @@
 #define ERRMSGSIZE  10000 /* Hope this is big enough.  No way to error check */
 #define LINEWIDTH      79 /* Max width of any output line */
 #define PREFIXLIMIT    30 /* Max width of the prefix on each line */
-void ErrorMsg(va_alist)
-va_dcl
+void ErrorMsg( char *filename, int lineno, char *format, ... )
 {
+  /*
   char *filename;
   int lineno;
   char *format;
+  */
   char errmsg[ERRMSGSIZE];
   char prefix[PREFIXLIMIT+10];
   int errmsgsize;
@@ -1106,10 +1107,12 @@
   va_list ap;
   int end, restart, base;
 
-  va_start(ap);
+  va_start(ap, format);
+  /*
   filename = va_arg(ap,char*);
   lineno = va_arg(ap,int);
   format = va_arg(ap,char*);
+  */
   /* Prepare a prefix to be prepended to every output line */
   if( lineno>0 ){
     sprintf(prefix,"%.*s:%d: ",PREFIXLIMIT-10,filename,lineno);
