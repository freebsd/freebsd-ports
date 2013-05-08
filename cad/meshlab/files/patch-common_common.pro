--- common/common.pro.orig	2013-05-07 10:06:45.000000000 +0200
+++ common/common.pro	2013-05-07 10:09:47.000000000 +0200
@@ -62,6 +62,9 @@
 linux-g++-64:CONFIG += dll
 linux-g++-64:DESTDIR = ../distrib
 
+freebsd:CONFIG += dll
+freebsd:DESTDIR = ../distrib
+
 win32-msvc2005:CONFIG += staticlib
 win32-msvc2008:CONFIG += staticlib
 win32-msvc2010:CONFIG += staticlib
@@ -124,5 +127,6 @@
 linux-g++:LIBS		+= -L../external/lib/linux-g++ -ljhead
 linux-g++-32:LIBS		+= -L../external/lib/linux-g++-32 -ljhead
 linux-g++-64:LIBS		+= -L../external/lib/linux-g++-64 -ljhead
+freebsd:LIBS		+= -L../external/lib/freebsd -ljhead
 	
 #RESOURCES = common.qrc
