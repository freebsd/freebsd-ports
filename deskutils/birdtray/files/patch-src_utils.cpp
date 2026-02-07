--- src/utils.cpp.orig	2020-11-08 19:41:30 UTC
+++ src/utils.cpp
@@ -200,7 +200,7 @@ QStringList Utils::getDefaultThunderbirdCommand() {
 #elif defined (Q_OS_WIN)
     return {R"("%ProgramFiles(x86)%\Mozilla Thunderbird\thunderbird.exe")"};
 #else
-    return { "/usr/bin/thunderbird" };
+    return { "%%LOCALBASE%%/bin/thunderbird" };
 #endif
 }
 
