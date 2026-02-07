--- apps/client/src/ui/dialogs/filedownloaddialog.cpp.orig	2023-06-26 18:10:09 UTC
+++ apps/client/src/ui/dialogs/filedownloaddialog.cpp
@@ -47,7 +47,7 @@ DENG_GUI_PIMPL(FileDownloadDialog)
         if (!bytes.end) return;
 
         auto &indicator = self().progressIndicator();
-        indicator.setProgress(round<int>(100.0 * double(bytes.size())/double(bytes.end)));
+        indicator.setProgress(de::round<int>(100.0 * double(bytes.size())/double(bytes.end)));
 
         indicator.setText(tr("%1\n" _E(l)_E(F) "%2 file%3 / %4 MB")
                           .arg(message)
