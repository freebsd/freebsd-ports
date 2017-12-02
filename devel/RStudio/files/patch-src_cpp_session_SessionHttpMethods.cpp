--- src/cpp/session/SessionHttpMethods.cpp.orig	2017-11-16 21:40:37 UTC
+++ src/cpp/session/SessionHttpMethods.cpp
@@ -326,7 +326,7 @@ std::string clientVersion()
       return std::string();
 
    // clientVersion is the git revision hash
-   return RSTUDIO_GIT_REVISION_HASH;
+   return RSTUDIO_VERSION;
 }
 
 void waitForMethodInitFunction(const ClientEvent& initEvent)
