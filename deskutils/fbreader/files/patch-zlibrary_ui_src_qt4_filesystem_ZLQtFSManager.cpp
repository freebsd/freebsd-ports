--- zlibrary/ui/src/qt4/filesystem/ZLQtFSManager.cpp.orig	2024-12-20 19:24:04 UTC
+++ zlibrary/ui/src/qt4/filesystem/ZLQtFSManager.cpp
@@ -27,7 +27,7 @@ std::string ZLQtFSManager::convertFilenameToUtf8(const
 	}
 
 	QString qString = QString::fromLocal8Bit(name.c_str());
-	return (qString == QString::null) ? "" : (const char*)qString.toUtf8();
+	return (qString == QString()) ? "" : (const char*)qString.toUtf8();
 }
 
 std::string ZLQtFSManager::mimeType(const std::string &path) const {
