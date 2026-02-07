--- XOptions/xoptions.h.orig	2021-08-30 16:51:52 UTC
+++ XOptions/xoptions.h
@@ -35,6 +35,9 @@
 #else
 #include <QCoreApplication> // TODO Check
 #endif
+#if defined(Q_OS_FREEBSD)
+#include <QStandardPaths>
+#endif
 
 class XOptions : public QObject
 {
