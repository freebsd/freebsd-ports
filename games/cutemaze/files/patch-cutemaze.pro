--- cutemaze.pro.orig	2017-07-30 17:16:25 UTC
+++ cutemaze.pro
@@ -91,14 +91,14 @@ macx {
 	desktop.path = $$PREFIX/share/applications/
 
 	appdata.files = icons/cutemaze.appdata.xml
-	appdata.path = $$PREFIX/share/metainfo/
+	appdata.path = $$PREFIX/share/appdata/
 
 	qm.files = $$replace(TRANSLATIONS, .ts, .qm)
 	qm.path = $$PREFIX/share/cutemaze/translations
 	qm.CONFIG += no_check_exist
 
 	man.files = doc/cutemaze.6
-	man.path = $$PREFIX/share/man/man6
+	man.path = $$PREFIX/man/man6
 
 	INSTALLS += target pixmap icon desktop appdata qm man
 }
