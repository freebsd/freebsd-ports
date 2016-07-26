--- qztest/qztest.pro.orig	2014-02-10 18:04:08 UTC
+++ qztest/qztest.pro
@@ -40,7 +40,10 @@ MOC_DIR = .moc
 
 win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quazip/release/ -lquazip
 else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quazip/debug/ -lquazip
-else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip
+else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip $$join(QMAKE_LIBDIR, " -L", -L) -L$$QMAKE_LIBDIR_QT
+
+QMAKE_LIBDIR=
+QMAKE_LIBDIR_QT=
 
 INCLUDEPATH += $$PWD/..
 DEPENDPATH += $$PWD/../quazip
