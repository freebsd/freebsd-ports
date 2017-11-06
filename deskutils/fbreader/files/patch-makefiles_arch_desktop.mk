--- makefiles/arch/desktop.mk.orig	2017-01-18 21:42:48 UTC
+++ makefiles/arch/desktop.mk
@@ -17,7 +17,7 @@ ifeq "$(UI_TYPE)" "qt"
   MOC = moc-qt3
   QTINCLUDE = -I /usr/include/qt3
 else
-  MOC = moc-qt4
+  MOC = moc
   QTINCLUDE = -I /usr/include/qt4
 endif
 
