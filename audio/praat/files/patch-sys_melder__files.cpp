--- sys/melder_files.cpp.orig	2015-03-24 09:58:31 UTC
+++ sys/melder_files.cpp
@@ -301,7 +301,7 @@ void MelderFile_setToNull (MelderFile fi
 }
 
 bool MelderFile_isNull (MelderFile file) {
-	return file == nullptr || file -> path [0] == '\0';
+	return file == NULL || file -> path [0] == '\0';
 }
 
 void MelderDir_setToNull (MelderDir dir) {
