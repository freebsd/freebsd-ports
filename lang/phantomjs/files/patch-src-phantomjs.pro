--- src/phantomjs.pro.orig	2015-04-03 17:42:14.245640426 +0900
+++ src/phantomjs.pro	2015-04-03 17:42:47.482878170 +0900
@@ -68,7 +68,7 @@
 include(linenoise/linenoise.pri)
 include(qcommandline/qcommandline.pri)
 
-linux*|mac|openbsd* {
+linux*|mac|openbsd*|freebsd* {
     INCLUDEPATH += breakpad/src
 
     SOURCES += breakpad/src/client/minidump_file_writer.cc \
