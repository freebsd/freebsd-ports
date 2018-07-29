--- src/WEDFileCache/WED_FileCache.cpp.orig	2018-07-04 19:57:32 UTC
+++ src/WEDFileCache/WED_FileCache.cpp
@@ -157,7 +157,7 @@ void CACHE_FileCacheInitializer::init()
 			}
 			else
 			{
-				paired_files.push_back(make_pair<string,string>(files[i], files[i+1]));
+				paired_files.push_back(make_pair(files[i], files[i+1]));
 				i += 2;
 			}
 		}
