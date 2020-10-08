--- 3rdparty/3rdparty.pri.orig	2020-10-08 14:45:47 UTC
+++ 3rdparty/3rdparty.pri
@@ -30,8 +30,10 @@ if(win32*):exists( $$PWD/qredisclient/qredisclient.lib
 include($$PWD/pyotherside.pri)
 
 #LZ4
-LZ4DIR = $$PWD/lz4/
-INCLUDEPATH += $$LZ4DIR/lib
+!defined(SYSTEM_LZ4, var) {
+    LZ4DIR = $$PWD/lz4/
+    INCLUDEPATH += $$LZ4DIR/lib
+}
 
 win32* {
     ZLIBDIR = $$PWD/zlib-msvc14-x64.1.2.11.7795/build/native    
@@ -56,7 +58,13 @@ unix:!macx { # ubuntu & debian   
         #QMAKE_LFLAGS = -Wl,-rpath=/home/user/Qt5.9.3/5.9.3/gcc_64/lib
     }
 
-    LIBS += -lz $$LZ4DIR/build/cmake/liblz4.a
+    LIBS += -lz
+    defined(SYSTEM_LZ4, var) {
+        LIBS += -llz4
+    } else {
+        LIBS += $$LZ4DIR/build/cmake/liblz4.a
+    }
+
 
     # Unix signal watcher
     defined(LINUX_SIGNALS, var) {
