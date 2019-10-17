--- src/cpp/session/SessionMain.cpp.orig	2019-09-19 13:59:21 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -1633,7 +1633,11 @@ int main (int argc, char * const argv[]) 
       
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
+#endif
 #endif
 
       // get main thread id (used to distinguish forks which occur
