--- src/ctagsfrontend.cpp.orig	Fri Jul  9 11:03:47 2004
+++ src/ctagsfrontend.cpp	Fri Jul  9 11:04:02 2004
@@ -81,7 +81,7 @@
 	QFileInfo fi(sPath);
 
 	if (!fi.exists() || !fi.isFile() || !fi.isExecutable() ||
-		fi.fileName().left(5) != "ctags") {
+		fi.fileName().left(7) != "exctags") {
 		KMessageBox::error(0, i18n("Ctags cannot be found in the given "
 			"path"));
 		return false;
