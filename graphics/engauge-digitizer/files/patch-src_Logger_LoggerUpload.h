--- src/Logger/LoggerUpload.h.orig	2025-11-24 05:39:46 UTC
+++ src/Logger/LoggerUpload.h
@@ -9,7 +9,7 @@
 
 #include <QtGlobal>
 
-#if defined(WIN32) || defined(WIN64)
+#if defined(WIN32) || defined(WIN64) || defined(__FreeBSD__)
 #define NO_RETURN_VALUE
 #else
 #define NO_RETURN_VALUE Q_NORETURN
