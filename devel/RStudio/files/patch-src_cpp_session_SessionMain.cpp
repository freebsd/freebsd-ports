--- src/cpp/session/SessionMain.cpp.orig	2020-01-23 23:30:24 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -1711,7 +1711,11 @@ int main (int argc, char * const argv[]) 
       
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
+#endif
 #endif
 
       // get main thread id (used to distinguish forks which occur
