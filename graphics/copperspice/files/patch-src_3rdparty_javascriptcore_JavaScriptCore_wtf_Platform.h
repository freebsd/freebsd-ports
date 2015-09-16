--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h.orig	2015-04-23 19:00:27 UTC
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h
@@ -405,7 +405,7 @@
 #endif
 
 /* OS(FREEBSD) - FreeBSD */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define WTF_OS_FREEBSD 1
 #endif
 
