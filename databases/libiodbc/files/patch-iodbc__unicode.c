--- iodbc/unicode.c.orig	Tue Aug 30 22:24:12 2005
+++ iodbc/unicode.c	Thu Nov 10 13:35:19 2005
@@ -192,6 +192,7 @@
 #if !defined(HAVE_TOWLOWER)
 #if (defined(__APPLE__) && !defined (_LP64)) || defined (macintosh)
 #include <Carbon/Carbon.h>
+#endif
 wchar_t towlower(wchar_t wc)
 {
 #ifdef __APPLE__
@@ -213,7 +214,6 @@
   return wc;
 #endif
 }
-#endif
 #endif
 
 #if !defined(HAVE_WCSNCASECMP)
