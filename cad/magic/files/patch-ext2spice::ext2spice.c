--- ext2spice/ext2spice.c.orig	Tue Dec  9 16:53:56 2003
+++ ext2spice/ext2spice.c	Tue Dec  9 16:55:34 2003
@@ -18,7 +18,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
-#include <varargs.h>
+#include <stdarg.h>
 #include "misc/magic.h"
 #include "utils/malloc.h"
 #include "utils/geometry.h"
@@ -316,7 +316,7 @@
 #ifdef	free_all_mem
     EFFlatDone(); 
     EFDone();
-#endif	free_all_mem
+#endif
 
     printf("Memory used: %s\n", RunStats(RS_MEM, NULL, NULL));
     exit (0);
@@ -1586,22 +1586,19 @@
 }
 
 /* debugging stuff */
-#include <varargs.h>
+#include <stdarg.h>
 
 #define DBG 1
 
-DBPRINT( va_alist )
-  va_dcl
+DBPRINT( char *fmt, ... )
   {
     va_list  args;
-    char     *fmt;
     FILE     *fp;
     char     buff[ 300 ];
 
     if ( DBG ) {
-    va_start( args );
+    va_start( args, fmt );
     fp = stderr ;
-    fmt = va_arg( args, char * );
     (void) vsprintf( buff, fmt, args );
     va_end( args );
 
