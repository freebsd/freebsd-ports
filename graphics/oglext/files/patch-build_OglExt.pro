--- build/OglExt.pro.orig	Thu Aug 19 23:58:56 2004
+++ build/OglExt.pro	Thu Aug 19 23:59:25 2004
@@ -2,9 +2,11 @@
 # Tue Jun 15 10:34:01 CET 2004
 
 TEMPLATE = lib
-CONFIG += dll warn_on release opengl
+CONFIG = dll warn_on release opengl
 TARGET = OglExt
 VERSION = 1.1.0
+
+INCLUDEPATH=	../include
 
 SOURCES += \
             OglExt.cpp \
