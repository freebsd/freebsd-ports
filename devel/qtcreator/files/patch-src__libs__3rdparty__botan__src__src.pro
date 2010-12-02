--- ./src/libs/3rdparty/botan/src/src.pro.orig	2010-08-24 11:46:09.000000000 +0400
+++ ./src/libs/3rdparty/botan/src/src.pro	2010-11-29 03:49:46.829707166 +0300
@@ -564,10 +564,6 @@
            timer/gettimeofday/tm_unix.cpp
 }
 
-linux*-g++* {
-    SOURCES += timer/posix_rt/tm_posix.cpp
-}
+SOURCES += timer/posix_rt/tm_posix.cpp
 
-linux*-g++* {
-    LIBS += -lrt
-}
+LIBS += -lrt
