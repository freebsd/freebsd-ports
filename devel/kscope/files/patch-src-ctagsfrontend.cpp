--- /homes/fmayhar/kscope-0.5/src/ctagsfrontend.cpp	Thu Dec 18 20:58:30 2003
+++ src/ctagsfrontend.cpp	Wed Apr 21 13:01:45 2004
@@ -81,7 +81,7 @@
 	QFileInfo fi(sPath);
 
 	if (!fi.exists() || !fi.isFile() || !fi.isExecutable() ||
-		fi.fileName() != "ctags") {
+		fi.fileName() != "exctags") {
 		KMessageBox::error(0, i18n("Ctags cannot be found in the given "
 			"path"));
 		return false;
