--- cutemaze.pro.orig	2017-02-13 13:47:42 UTC
+++ cutemaze.pro
@@ -94,7 +94,7 @@ macx {
 	qm.CONFIG += no_check_exist
 
 	man.files = doc/cutemaze.6
-	man.path = $$PREFIX/share/man/man6
+	man.path = $$PREFIX/man/man6
 
 	INSTALLS += target pixmap icon desktop appdata qm man
 }
