--- src/lcllib.c.orig	Wed Oct 30 17:51:13 2002
+++ src/lcllib.c	Wed Oct 30 22:37:48 2002
@@ -49,13 +49,7 @@
 extern /*:open:*/ /*@dependent@*/ FILE *yyin;
 /*@=incondefs@*/ /*@=redecl@*/
 
-/*@constant int NUMLIBS; @*/
-# define NUMLIBS 25
-
-/*@constant int NUMPOSIXLIBS; @*/
-# define NUMPOSIXLIBS 18
-
-static ob_mstring posixlibs[NUMPOSIXLIBS] = 
+static ob_mstring posixlibs[] = 
 {
   "dirent",
   "fcntl",
@@ -77,7 +71,10 @@
   "utime"
 } ;
 
-static ob_mstring stdlibs[NUMLIBS] =
+/*@constant int NUMPOSIXLIBS; @*/
+# define NUMPOSIXLIBS (sizeof(posixlibs) / sizeof(posixlibs[0]))
+
+static ob_mstring stdlibs[] =
 {
   "assert", 
   "complex"
@@ -85,7 +82,10 @@
   "errno",
   "fenv",
   "float",
+#ifndef __FreeBSD__ 
+/* inttypes.h needs to be parsed on FreeBSD so some defines are known */
   "inttypes",
+#endif
   "iso646",
   "limits",
   "locale",
@@ -105,6 +105,9 @@
   "wchar",
   "wctype"
 } ;
+
+/*@constant int NUMLIBS; @*/
+# define NUMLIBS (sizeof(stdlibs) / sizeof(stdlibs[0]))
 
 static bool loadLCDFile (FILE * p_f, cstring p_name);
 
