--- src/qt/config.tests/x11/fontconfig/fontconfig.pro.orig	2013-12-31 13:08:24.457123877 +0900
+++ src/qt/config.tests/x11/fontconfig/fontconfig.pro	2013-12-31 13:08:35.878125769 +0900
@@ -1,5 +1,4 @@
 SOURCES = fontconfig.cpp
-CONFIG += x11
 CONFIG -= qt
 LIBS += -lfreetype -lfontconfig
 include(../../unix/freetype/freetype.pri)
