--- src/risklib.c.orig	Wed Oct 27 11:02:08 1993
+++ src/risklib.c	Sat Nov 15 15:43:46 2003
@@ -1,18 +1,16 @@
 #include "xrisk.h"
 #include "xrisklibex.h"
-#include <varargs.h>
+#include <stdarg.h>
 #include <ctype.h>
 
 /* Function to jump to when writing error_msg etc., extits to unix */
-void risk_exit(format,va_alist)
-     char *format;
-     va_dcl
+void risk_exit(char *format,...)
 {
   va_list  ap;
   char    *args[5];
   int      argno = 0;
   
-  va_start (ap);
+  va_start (ap, format);
   while ((argno<5)&&((args[argno++] = va_arg(ap, char *)) != LAST_ARG));
   va_end (ap);
   fprintf(stderr,format,args[0],args[1],args[2],args[3],args[4]);
@@ -126,17 +124,14 @@
 }
 
 /* Write msg with arguments to user */ 
-void write_msg_arg(player,va_alist)
-     playerp player;
-     va_dcl
+void write_msg_arg(playerp player,char *file,...)
 {
   va_list  ap;
-  char    *file;
   char    *args[5];
   char     msg[MAXLEN_MISC];
   int      argno = 0;
-  va_start (ap);
-  file = mappet(va_arg(ap, char *));
+  va_start (ap, file);
+  file = mappet(file);
   while ((argno<5)&&((args[argno++] = va_arg(ap, char *)) != LAST_ARG));
   va_end (ap);
   mappargs(file,args,argno);
@@ -176,16 +171,14 @@
 }
 
 /* Write a message with arguments to all players */
-void write_msg_all_arg(va_alist)
-     va_dcl
+void write_msg_all_arg(char *file,...)
 {
   va_list  ap;
-  char    *file;
   char    *args[5];
   char     msg[MAXLEN_MISC];
   int argno = 0;
-  va_start (ap);
-  file = mappet(va_arg(ap, char *));
+  va_start (ap, file);
+  file = mappet(file);
   while ((argno<5)&& ((args[argno++] = va_arg(ap, char *)) != LAST_ARG) );
   va_end (ap);
   mappargs(file,args,argno);
