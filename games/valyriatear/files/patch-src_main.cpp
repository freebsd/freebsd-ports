--- src/main.cpp.orig	2016-04-25 20:52:18 UTC
+++ src/main.cpp
@@ -459,7 +459,7 @@ int main(int argc, char *argv[])
         chdir(path.c_str());
 #elif (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(SOLARIS)) && !defined(RELEASE_BUILD)
         // Look for data files in DATADIR only if they are not available in the current directory.
-        if(std::ifstream("dat/config/settings.lua") == NULL) {
+        if(!std::ifstream("dat/config/settings.lua").good()) {
             if(chdir(PKG_DATADIR) != 0) {
                 throw Exception("ERROR: failed to change directory to data location", __FILE__, __LINE__, __FUNCTION__);
             }
