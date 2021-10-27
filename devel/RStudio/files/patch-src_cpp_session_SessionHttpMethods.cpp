--- src/cpp/session/SessionHttpMethods.cpp.orig	2021-09-22 13:58:50 UTC
+++ src/cpp/session/SessionHttpMethods.cpp
@@ -437,7 +437,7 @@ std::string clientVersion()
       return std::string();
 
    // clientVersion is the git revision hash
-   return RSTUDIO_GIT_REVISION_HASH;
+   return RSTUDIO_VERSION;
 }
 
 bool protocolDebugEnabled()
