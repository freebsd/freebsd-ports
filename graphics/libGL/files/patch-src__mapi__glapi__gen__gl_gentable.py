--- src/mapi/glapi/gen/gl_gentable.py.orig	2014-11-21 13:09:28.624910062 +0100
+++ src/mapi/glapi/gen/gl_gentable.py	2014-11-21 13:10:48.294268333 +0100
@@ -42,7 +42,7 @@
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
