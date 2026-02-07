--- src/filesystem.cpp.orig	2012-12-08 22:36:13 UTC
+++ src/filesystem.cpp
@@ -405,8 +405,14 @@ void get_files_in_dir(const std::string&
 	}
 #else
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
@@ -437,14 +443,14 @@ void get_files_in_dir(const std::string&
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
