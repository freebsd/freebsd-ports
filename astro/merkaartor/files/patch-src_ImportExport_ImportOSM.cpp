--- src/ImportExport/ImportOSM.cpp.orig	2022-06-11 16:30:43 UTC
+++ src/ImportExport/ImportOSM.cpp
@@ -541,9 +541,9 @@ bool importOSM(QWidget* aParent, QIODevice& File, Docu
         }
 
         if (EmptyFeature.size()) {
-            if (QMessageBox::warning(aParent,QApplication::translate("Downloader","Empty roads/relations detected"),
+            if (QMessageBox::warning(aParent,QApplication::translate("Downloader","Empty ways/relations detected"),
                     QApplication::translate("Downloader",
-                    "Empty roads/relations are probably errors.\n"
+                    "Empty ways/relations are probably errors.\n"
                     "Do you want to mark them for deletion?"),
                     QMessageBox::Ok | QMessageBox::Cancel,
                     QMessageBox::Cancel
@@ -590,6 +590,3 @@ bool importOSM(QWidget* aParent, QByteArray& Content, 
     File.open(QIODevice::ReadOnly);
     return importOSM(aParent, File, theDocument, theLayer, theDownloader);
 }
-
-
-
