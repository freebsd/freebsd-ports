--- src/platform/crashhandler/CrashHandlerPOSIX.cpp.orig	2021-07-14 00:04:34 UTC
+++ src/platform/crashhandler/CrashHandlerPOSIX.cpp
@@ -246,7 +246,7 @@ static fs::path getCoreDumpFile() {
 	size_t start = 0;
 	while(start < pattern.length()) {
 		
-		size_t end = pattern.find('%');
+		size_t end = pattern.find('%', start);
 		if(end == std::string::npos) {
 			end = pattern.length();
 		}
