--- pcsx2-qt/AutoUpdaterDialog.cpp.orig	2024-04-11 09:34:32 UTC
+++ pcsx2-qt/AutoUpdaterDialog.cpp
@@ -892,7 +892,7 @@ void AutoUpdaterDialog::cleanupAfterUpdate()
 
 #else
 
-bool AutoUpdaterDialog::processUpdate(const QByteArray& update_data, QProgressDialog& progress)
+bool AutoUpdaterDialog::processUpdate(const std::vector<u8>& data, QProgressDialog&)
 {
 	return false;
 }
