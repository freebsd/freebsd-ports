--- jsosdep.h	2006-07-07 04:12:02.000000000 +0200
+++ jsosdep.h	2008-06-19 16:32:12.000000000 +0200
@@ -89,7 +89,7 @@
 #elif defined(SOLARIS)
 #define JS_HAVE_LONG_LONG
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__FreeBSD__)
 #define JS_HAVE_LONG_LONG
 
 #elif defined(SUNOS4)
