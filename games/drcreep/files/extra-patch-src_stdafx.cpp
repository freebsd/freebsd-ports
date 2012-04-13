Index: src/stdafx.cpp
@@ -364,7 +364,7 @@
 
 string findType;
 
-int file_select(const struct dirent *entry) {
+int file_select(struct dirent *entry) {
 	string name = entry->d_name;
 
 	transform( name.begin(), name.end(), name.begin(), ::toupper );
