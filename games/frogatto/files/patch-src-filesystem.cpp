--- src/filesystem.cpp.orig
+++ src/filesystem.cpp
@@ -299,8 +299,14 @@
 					  FILE_NAME_MODE mode)
 {
 	struct stat st;
+	std::string dirname;
 
-	DIR* dir = opendir(directory.c_str());
+	if(have_datadir)
+		dirname = data_dir + "/" + directory;
+	else
+		dirname = directory;
+
+	DIR* dir = opendir(dirname.c_str());
 
 	if(dir == NULL) {
 		return;
@@ -331,14 +337,14 @@
 #endif /* !APPLE */
 
 		std::string fullname;
-		if (directory.empty() || directory[directory.size()-1] == '/'
+		if (dirname.empty() || dirname[dirname.size()-1] == '/'
 #ifdef __AMIGAOS4__
-			|| (directory[directory.size()-1]==':')
+			|| (dirname[dirname.size()-1]==':')
 #endif /* __AMIGAOS4__ */
 		)
-			fullname = directory + basename;
+			fullname = dirname + basename;
 		else
-			fullname = (directory + "/") + basename;
+			fullname = (dirname + "/") + basename;
 
 		if (::stat(fullname.c_str(), &st) != -1) {
 			if (S_ISREG(st.st_mode)) {
