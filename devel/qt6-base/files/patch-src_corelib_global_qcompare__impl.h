Add missing include. This was pulled in from <QtCore/qglobal.h> before [1].

[1] https://code.qt.io/cgit/qt/qtbase.git/commit/src/corelib/global/qcompare_impl.h?id=0677d334f85f6d39f6f6495162eec69712e42370

--- src/corelib/global/qcompare_impl.h.orig	2026-05-11 20:54:55 UTC
+++ src/corelib/global/qcompare_impl.h
@@ -10,6 +10,10 @@
 #pragma qt_sync_stop_processing
 #endif
 
+#ifdef __cplusplus
+#  include <type_traits>
+#endif
+
 #include <QtCore/qtconfigmacros.h>
 #include <QtCore/qcompilerdetection.h>
 
