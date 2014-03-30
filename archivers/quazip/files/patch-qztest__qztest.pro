--- ./qztest/qztest.pro.orig	2014-02-09 12:36:57.000000000 +0100
+++ ./qztest/qztest.pro	2014-03-30 05:01:44.000000000 +0200
@@ -39,7 +39,10 @@
 
 win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quazip/release/ -lquazip
 else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quazip/debug/ -lquazip
-else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip
+else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip $$join(QMAKE_LIBDIR, " -L", -L) -L$$QMAKE_LIBDIR_QT
+
+QMAKE_LIBDIR=
+QMAKE_LIBDIR_QT=
 
 INCLUDEPATH += $$PWD/..
 DEPENDPATH += $$PWD/../quazip
