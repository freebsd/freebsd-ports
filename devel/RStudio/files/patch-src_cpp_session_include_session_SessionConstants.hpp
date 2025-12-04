- Use system copilot-language-server from github-copilot-language-server port
- Path must be directory containing the executable, not the executable itself

--- src/cpp/session/include/session/SessionConstants.hpp.orig	2025-11-30 08:22:15 UTC
+++ src/cpp/session/include/session/SessionConstants.hpp
@@ -158,7 +158,7 @@
 
 #define kDefaultNodePath           "bin/node"
 #define kDefaultQuartoPath         "bin/quarto"
-#define kDefaultCopilotPath        "bin/copilot-language-server"
+#define kDefaultCopilotPath        "%%LOCALBASE%%/bin"
 #define kDefaultRsclangPath        "bin/rsclang"
 
 #ifdef _WIN32
