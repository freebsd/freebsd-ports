--- src/libUnicorn/TrackInfo.h.orig	2016-07-26 15:06:09 UTC
+++ src/libUnicorn/TrackInfo.h
@@ -33,6 +33,8 @@
 #include <QStringList>
 #include <QUrl>
 
+#include <sys/time.h>
+
 
 class UNICORN_DLLEXPORT TrackInfo
 {
