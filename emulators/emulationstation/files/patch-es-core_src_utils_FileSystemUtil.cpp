--- es-core/src/utils/FileSystemUtil.cpp.orig	2023-12-18 20:00:52 UTC
+++ es-core/src/utils/FileSystemUtil.cpp
@@ -578,10 +578,10 @@ namespace Utils
 				CloseHandle(hFile);
 			}
 #else // _WIN32
-			struct stat64 info;
+			struct stat info;
 
-			// check if lstat64 succeeded
-			if(lstat64(path.c_str(), &info) == 0)
+			// check if lstat succeeded
+			if(lstat(path.c_str(), &info) == 0)
 			{
 				resolved.resize(info.st_size);
 				if(readlink(path.c_str(), (char*)resolved.data(), resolved.size()) > 0)
@@ -658,9 +658,9 @@ namespace Utils
 			if(pathExistsIndex.find(_path) == pathExistsIndex.cend())
 			{
 				const std::string path = getGenericPath(_path);
-				struct stat64 info;
-				// check if stat64 succeeded
-				pathExistsIndex[_path] = (stat64(path.c_str(), &info) == 0);
+				struct stat info;
+				// check if stat succeeded
+				pathExistsIndex[_path] = (stat(path.c_str(), &info) == 0);
 			}
 
 			return pathExistsIndex.at(_path);
@@ -686,10 +686,10 @@ namespace Utils
 		bool isRegularFile(const std::string& _path)
 		{
 			const std::string path = getGenericPath(_path);
-			struct stat64     info;
+			struct stat     info;
 
-			// check if stat64 succeeded
-			if(stat64(path.c_str(), &info) != 0)
+			// check if stat succeeded
+			if(stat(path.c_str(), &info) != 0)
 				return false;
 
 			// check for S_IFREG attribute
@@ -702,10 +702,10 @@ namespace Utils
 		bool isDirectory(const std::string& _path)
 		{
 			const std::string path = getGenericPath(_path);
-			struct stat64     info;
+			struct stat     info;
 
-			// check if stat64 succeeded
-			if(stat64(path.c_str(), &info) != 0)
+			// check if stat succeeded
+			if(stat(path.c_str(), &info) != 0)
 				return false;
 
 			// check for S_IFDIR attribute
@@ -725,10 +725,10 @@ namespace Utils
 			if((Attributes != INVALID_FILE_ATTRIBUTES) && (Attributes & FILE_ATTRIBUTE_REPARSE_POINT))
 				return true;
 #else // _WIN32
-			struct stat64 info;
+			struct stat info;
 
-			// check if lstat64 succeeded
-			if(lstat64(path.c_str(), &info) != 0)
+			// check if lstat succeeded
+			if(lstat(path.c_str(), &info) != 0)
 				return false;
 
 			// check for S_IFLNK attribute
@@ -772,10 +772,10 @@ namespace Utils
 			// regular files and executables, but not setuid, setgid, shared text
 			const mode_t mask = S_IFREG;
 			const mode_t mask_exec = S_IXUSR | S_IXGRP | S_IXOTH;
-			struct stat64 info;
+			struct stat info;
 
-			// check if stat64 succeeded
-			if(stat64(path.c_str(), &info) != 0)
+			// check if stat succeeded
+			if(stat(path.c_str(), &info) != 0)
 				return false;
 
 			// check for mask attributes
