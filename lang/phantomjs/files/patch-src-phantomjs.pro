--- src/phantomjs.pro.orig	2013-10-01 10:49:57.204247173 +0900
+++ src/phantomjs.pro	2013-10-01 10:50:42.830414131 +0900
@@ -60,7 +60,7 @@
 include(linenoise/linenoise.pri)
 include(qcommandline/qcommandline.pri)
 
-linux*|mac {
+linux*|mac|freebsd* {
     INCLUDEPATH += breakpad/src
 
     SOURCES += breakpad/src/client/minidump_file_writer.cc \
