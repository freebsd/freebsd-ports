--- zlibrary/ui/src/qt4/dialogs/ZLQtUtil.cpp.orig	2024-12-20 19:20:14 UTC
+++ zlibrary/ui/src/qt4/dialogs/ZLQtUtil.cpp
@@ -27,7 +27,7 @@ QString qtButtonName(const ZLResourceKey &key) {
 
 QString qtButtonName(const ZLResourceKey &key) {
 	if (key.Name.empty()) {
-		return QString::null;
+		return QString();
 	}
 	return ::qtString(ZLDialogManager::buttonName(key));
 }
