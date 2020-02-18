--- src/cpp/session/SessionHttpMethods.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/session/SessionHttpMethods.cpp
@@ -397,7 +397,7 @@ std::string clientVersion()
       return std::string();
 
    // clientVersion is the git revision hash
-   return RSTUDIO_GIT_REVISION_HASH;
+   return RSTUDIO_VERSION;
 }
 
 void waitForMethodInitFunction(const ClientEvent& initEvent)
