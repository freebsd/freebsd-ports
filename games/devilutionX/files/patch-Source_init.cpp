--- Source/init.cpp.orig	2022-04-25 02:21:41 UTC
+++ Source/init.cpp
@@ -90,7 +90,7 @@ std::vector<std::string> GetMPQSearchPaths()
 	if (paths[0] == paths[1])
 		paths.pop_back();
 
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__FreeBSD__)
 	paths.emplace_back("/usr/share/diasurgical/devilutionx/");
 	paths.emplace_back("/usr/local/share/diasurgical/devilutionx/");
 #elif defined(__3DS__) || defined(__SWITCH__)
