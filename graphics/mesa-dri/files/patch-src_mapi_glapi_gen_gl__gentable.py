--- src/mapi/glapi/gen/gl_gentable.py.orig	2017-05-15 12:05:59 UTC
+++ src/mapi/glapi/gen/gl_gentable.py
@@ -43,7 +43,7 @@ header = """/* GLXEXT is the define used
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
