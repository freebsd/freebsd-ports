std::filesystem::path::u8string may return std::string depending on standard

--- src/util/path_util.h.orig	2021-08-22 18:46:24 UTC
+++ src/util/path_util.h
@@ -31,7 +31,7 @@ namespace wyrmgus::path {
 inline std::string to_string(const std::filesystem::path &path)
 {
 	//convert a path to a UTF-8 encoded string
-	const std::u8string u8str = path.u8string();
+	const auto u8str = path.u8string();
 	return std::string(u8str.begin(), u8str.end());
 }
 
