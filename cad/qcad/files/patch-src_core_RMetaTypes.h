--- src/core/RMetaTypes.h.orig	2013-10-07 15:13:12.654243671 +0300
+++ src/core/RMetaTypes.h	2013-10-07 15:13:24.530910626 +0300
@@ -125,7 +125,7 @@
 Q_DECLARE_METATYPE(unsigned int*)
 Q_DECLARE_METATYPE(qint64*)
 
-#if !defined Q_OS_WIN32 && !defined Q_OS_LINUX
+#if !defined Q_OS_WIN32 && !defined Q_OS_LINUX && !defined Q_OS_FREEBSD
 Q_DECLARE_METATYPE(size_t*)
 #endif
