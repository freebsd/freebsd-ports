--- tools/linguist/lrelease/lrelease.pro.orig	2015-02-23 21:14:17 UTC
+++ tools/linguist/lrelease/lrelease.pro
@@ -2,6 +2,8 @@ TEMPLATE        = app
 TARGET          = lrelease
 DESTDIR         = ../../../bin
 
+QT -= gui
+
 DEFINES += QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII
 SOURCES += main.cpp
 
