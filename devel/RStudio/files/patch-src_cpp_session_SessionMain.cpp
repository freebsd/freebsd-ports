--- src/cpp/session/SessionMain.cpp.orig	2022-12-03 07:38:59 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -1947,7 +1947,11 @@ int main(int argc, char * const argv[])
 
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
+#endif
 #endif
 
       logStartingEnv();
