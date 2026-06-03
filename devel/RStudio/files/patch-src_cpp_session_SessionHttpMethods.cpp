- Use RSTUDIO_VERSION instead of git hash for client version

--- src/cpp/session/SessionHttpMethods.cpp.orig	2025-05-30 14:20:38 UTC
+++ src/cpp/session/SessionHttpMethods.cpp
@@ -419,7 +419,7 @@ std::string clientVersion()
       return std::string();
 
    // clientVersion is the git revision hash
-   return RSTUDIO_GIT_REVISION_HASH;
+   return RSTUDIO_VERSION;
 }
 
 bool protocolDebugEnabled()
