--- 3rdparty/3rdparty.pri.orig	2018-04-23 05:41:30 UTC
+++ 3rdparty/3rdparty.pri
@@ -81,8 +81,6 @@ unix:!macx { # ubuntu & debian
         #QMAKE_LFLAGS = -Wl,-rpath=/home/user/Qt5.9.3/5.9.3/gcc_64/lib
     }
 
-    LIBS += $$BREAKPADDIR/client/linux/libbreakpad_client.a
-
     # Unix signal watcher
     HEADERS += $$PWD/qt-unix-signals/sigwatch.h
     SOURCES += $$PWD/qt-unix-signals/sigwatch.cpp
