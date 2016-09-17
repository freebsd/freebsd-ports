--- qztest/qztest.pro.orig	2016-03-01 15:20:57 UTC
+++ qztest/qztest.pro
@@ -43,7 +43,10 @@ MOC_DIR = .moc
 win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quazip/release/ -lquazip
 else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quazip/debug/ -lquazipd
 else:mac:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quazip/debug/ -lquazip_debug
-else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip
+else:unix: LIBS += -L$$OUT_PWD/../quazip/ -lquazip $$join(QMAKE_LIBDIR, " -L", -L) -L$$QMAKE_LIBDIR_QT
+
+QMAKE_LIBDIR=
+QMAKE_LIBDIR_QT=
 
 INCLUDEPATH += $$PWD/..
 DEPENDPATH += $$PWD/../quazip
