--- src/qsa/qsa.pro.orig	Mon Oct 18 16:26:30 2004
+++ src/qsa/qsa.pro	Mon Oct 18 16:26:49 2004
@@ -70,7 +70,8 @@
 		qsinterpreter.h \
 		qsargument.h \
 		qsinputdialogfactory.h \
-		qsscript.h
+		qsscript.h \
+		qsutilfactory.h
 
 !isEmpty(QSA_INSTALL_PREFIX) {
   headers.path = $$QSA_INSTALL_PREFIX/include
