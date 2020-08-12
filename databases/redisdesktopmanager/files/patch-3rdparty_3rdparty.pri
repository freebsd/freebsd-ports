--- 3rdparty/3rdparty.pri.orig	2020-08-10 20:11:17 UTC
+++ 3rdparty/3rdparty.pri
@@ -53,15 +53,16 @@ unix:!macx { # ubuntu & debian   
         #QMAKE_LFLAGS = -Wl,-rpath=/home/user/Qt5.9.3/5.9.3/gcc_64/lib
     }
 
+    # Unix signal watcher
+    DEFINES += LINUX_SIGNALS
+
     LIBS += -lz
 
     # Unix signal watcher
-    defined(LINUX_SIGNALS, var) {
-        message("Build with qt-unix-signals")
+    message("Build with qt-unix-signals")
 
-        DEFINES += LINUX_SIGNALS
-        HEADERS += $$PWD/qt-unix-signals/sigwatch.h
-        SOURCES += $$PWD/qt-unix-signals/sigwatch.cpp
-        INCLUDEPATH += $$PWD/qt-unix-signals/
-    }
+    DEFINES += LINUX_SIGNALS
+    HEADERS += $$PWD/qt-unix-signals/sigwatch.h
+    SOURCES += $$PWD/qt-unix-signals/sigwatch.cpp
+    INCLUDEPATH += $$PWD/qt-unix-signals/
 }
