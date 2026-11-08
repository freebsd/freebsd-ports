--- src/utils.cpp.orig	2023-09-03 22:44:59 UTC
+++ src/utils.cpp
@@ -204,7 +204,7 @@ QStringList Utils::getDefaultThunderbirdCommand() {
     }
     return {R"("%ProgramFiles(x86)%\Mozilla Thunderbird\thunderbird.exe")"};
 #else
-    return { "/usr/bin/thunderbird" };
+    return { "%%LOCALBASE%%/bin/thunderbird" };
 #endif
 }
 
