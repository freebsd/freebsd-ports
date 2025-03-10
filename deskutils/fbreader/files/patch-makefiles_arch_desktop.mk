--- makefiles/arch/desktop.mk.orig	2014-01-11 12:45:25 UTC
+++ makefiles/arch/desktop.mk
@@ -17,8 +17,8 @@ else
   MOC = moc-qt3
   QTINCLUDE = -I /usr/include/qt3
 else
-  MOC = moc-qt4
-  QTINCLUDE = -I /usr/include/qt4
+  MOC = libexec/qt6/moc
+  QTINCLUDE = -I /usr/include/qt6
 endif
 
 GTKINCLUDE = $(shell pkg-config --cflags gtk+-2.0 libpng xft)
@@ -28,7 +28,7 @@ ifeq "$(UI_TYPE)" "qt4"
 endif
 
 ifeq "$(UI_TYPE)" "qt4"
-  UILIBS = -lQtGui
+  UILIBS = $(shell pkg-config --libs Qt6Widgets)
 endif
 
 ifeq "$(UI_TYPE)" "gtk"
