--- lib/scanargs.c.orig	1992-02-28 06:18:15.000000000 +0900
+++ lib/scanargs.c	2012-10-15 22:09:52.000000000 +0900
@@ -42,6 +42,7 @@
 
 #include "rle_config.h"
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #ifndef USE_STDARG
 #include <varargs.h>
@@ -128,10 +129,10 @@
 va_list argl;
 {
 
-    register    check;			/* check counter to be sure all argvs
+    register int  check;		/* check counter to be sure all argvs
 					   are processed */
     register CONST_DECL char  *cp;
-    register    cnt;
+    register int  cnt;
     int	    optarg = 0;			/* where optional args start */
     int	    nopt = 0;
     char    tmpflg,			/* temp flag */
@@ -408,7 +409,8 @@
 				 * Copy the string so we remain nondestructive
 				 */
 				s = NEW( char, strlen(argp)+1 );
-				strcpy( s, argp );
+				strncpy( s, argp, sizeof(s)-1 );
+				s[sizeof(s) - 1] = '\0';
 				argp = s;
 
 				/* 
