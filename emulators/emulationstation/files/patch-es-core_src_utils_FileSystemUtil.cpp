--- es-core/src/utils/FileSystemUtil.cpp.orig	2020-11-29 11:37:59 UTC
+++ es-core/src/utils/FileSystemUtil.cpp
@@ -577,10 +577,10 @@ namespace Utils
 		bool exists(const std::string& _path)
 		{
 			std::string path = getGenericPath(_path);
-			struct stat64 info;
+			struct stat info;
 
 			// check if stat64 succeeded
-			return (stat64(path.c_str(), &info) == 0);
+			return (stat(path.c_str(), &info) == 0);
 
 		} // exists
 
@@ -599,10 +599,10 @@ namespace Utils
 		bool isRegularFile(const std::string& _path)
 		{
 			std::string path = getGenericPath(_path);
-			struct stat64 info;
+			struct stat info;
 
 			// check if stat64 succeeded
-			if(stat64(path.c_str(), &info) != 0)
+			if(stat(path.c_str(), &info) != 0)
 				return false;
 
 			// check for S_IFREG attribute
@@ -670,8 +670,8 @@ namespace Utils
 		} // isHidden
 #ifndef WIN32 // osx / linux
 		bool isExecutable(const std::string& _path) {
-			struct stat64 st;
-			if(stat64(_path.c_str(), &st) == 0){
+			struct stat st;
+			if(stat(_path.c_str(), &st) == 0){
 				mode_t perm = st.st_mode;
 				// regular files and executables but not setuid, setgid, shared text (mode 0755)
 				mode_t mask = S_IFREG | S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
