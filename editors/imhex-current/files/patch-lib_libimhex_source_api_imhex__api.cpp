--- lib/libimhex/source/api/imhex_api.cpp.orig	2024-03-02 15:44:54 UTC
+++ lib/libimhex/source/api/imhex_api.cpp
@@ -658,7 +658,7 @@ namespace hex {
             #if defined(OS_WINDOWS)
                 return "Windows";
             #elif defined(OS_LINUX)
-                return "Linux";
+                return "FreeBSD";
             #elif defined(OS_MACOS)
                 return "macOS";
             #elif defined(OS_WEB)
