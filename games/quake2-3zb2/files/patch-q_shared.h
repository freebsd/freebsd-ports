--- ./q_shared.h.orig	Sat Dec 30 19:09:03 2006
+++ ./q_shared.h	Sat Dec 30 19:09:23 2006
@@ -23,7 +23,7 @@
 #include <stdlib.h>
 #include <time.h>
 
-#if defined _M_IX86 && !defined C_ONLY
+#if (defined _M_IX86 || defined __i386__) && !defined C_ONLY && !defined __sun__
 #define id386	1
 #else
 #define id386	0
@@ -128,7 +128,7 @@
 // microsoft's fabs seems to be ungodly slow...
 //float Q_fabs (float f);
 //#define	fabs(f) Q_fabs(f)
-#if !defined C_ONLY
+#if !defined C_ONLY && !defined __unix__  && !defined __sgi
 extern long Q_ftol( float f );
 #else
 #define Q_ftol( f ) ( long ) (f)
@@ -1155,5 +1155,11 @@
 extern int vidref_val;
 // PGM
 // ==================
+
+#ifdef __unix__
+#define stricmp strcasecmp 
+#define _stricmp strcasecmp 
+#define _strnicmp strncasecmp
+#endif
 
 #endif
