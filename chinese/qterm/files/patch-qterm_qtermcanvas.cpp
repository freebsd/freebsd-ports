--- qterm/qtermcanvas.cpp.orig	Fri Dec 17 19:26:35 2004
+++ qterm/qtermcanvas.cpp	Fri Dec 17 19:26:39 2004
@@ -238,7 +238,7 @@
 	if(strSave.isEmpty())
 		return;
 	QString fmt = fi.extension(false).upper();
-	if(!pxm.save(strSave, fmt=="JPG"?"JPEG":fmt))
+	if(!pxm.save(strSave, fmt=="JPG"?QString("JPEG"):fmt))
 		QMessageBox::warning(this, "Failed to save file", "Cant save file, maybe format not supported");
 }
 
