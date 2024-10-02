--- src/cpp/session/SessionHttpMethods.cpp.orig	2024-06-04 21:19:10 UTC
+++ src/cpp/session/SessionHttpMethods.cpp
@@ -422,7 +422,7 @@ std::string clientVersion()
       return std::string();
 
    // clientVersion is the git revision hash
-   return RSTUDIO_GIT_REVISION_HASH;
+   return RSTUDIO_VERSION;
 }
 
 bool protocolDebugEnabled()
