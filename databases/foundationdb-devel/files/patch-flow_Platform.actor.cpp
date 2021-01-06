--- flow/Platform.actor.cpp.orig	2021-01-03 23:00:51 UTC
+++ flow/Platform.actor.cpp
@@ -2406,7 +2406,7 @@ ACTOR Future<vector<std::string>> findFiles( std::stri
 	return result;
 }
 
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__))
 #define FILE_ATTRIBUTE_DATA mode_t
 
 bool acceptFile( FILE_ATTRIBUTE_DATA fileAttributes, std::string const& name, std::string const& extension ) {
