--- getopt.c.orig	Wed Sep  1 17:49:35 1999
+++ src/getopt.c	Wed Apr 18 13:26:19 2001
@@ -73,9 +73,9 @@
 
 #ifdef VMS
 #include <unixlib.h>
-#if HAVE_STRING_H - 0
-#include <string.h>
 #endif
+#if HAVE_STRING_H
+#include <string.h>
 #endif
 
 #if defined (WIN32) && !defined (__CYGWIN32__)
@@ -650,6 +650,7 @@
 				else
 				{
 					if (opterr)
+					{
 						if (argv[optind - 1][1] == '-')
 							/* --option */
 							fprintf(stderr,
@@ -660,6 +661,7 @@
 							fprintf(stderr,
 								_("%s: option `%c%s' doesn't allow an argument\n"),
 								argv[0], argv[optind - 1][0], pfound->name);
+					}
 
 					nextchar += strlen(nextchar);
 
