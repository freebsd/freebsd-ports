--- src/core/RMetaTypes.h.orig	2013-08-06 17:32:09.000000000 +0200
+++ src/core/RMetaTypes.h	2013-08-08 10:41:01.000000000 +0200
@@ -121,7 +121,7 @@
 Q_DECLARE_METATYPE(unsigned int*)
 Q_DECLARE_METATYPE(qint64*)
 //Q_DECLARE_METATYPE(uint8_t*)
-#if !defined Q_OS_WIN32 && !defined Q_OS_LINUX
+#if !defined Q_OS_WIN32 && !defined Q_OS_LINUX && !defined Q_OS_FREEBSD
 Q_DECLARE_METATYPE(size_t*)
 #endif
 Q_DECLARE_METATYPE(char*)
