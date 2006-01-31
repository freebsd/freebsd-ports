--- iodbcinst/unicode.c.orig	Mon Jan 23 19:30:26 2006
+++ iodbcinst/unicode.c	Tue Jan 31 13:51:36 2006
@@ -197,6 +197,7 @@
 #if !defined(HAVE_TOWLOWER)
 #if (defined(__APPLE__) && !defined (_LP64)) || defined (macintosh)
 #include <Carbon/Carbon.h>
+#endif
 wchar_t towlower(wchar_t wc)
 {
 #if defined (__APPLE__) && !defined (NO_FRAMEWORKS)
@@ -218,7 +219,6 @@
   return wc;
 #endif
 }
-#endif
 #endif
 
 #if !defined(HAVE_WCSNCASECMP)
