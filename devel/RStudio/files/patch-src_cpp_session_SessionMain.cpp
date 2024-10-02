--- src/cpp/session/SessionMain.cpp.orig	2024-09-16 17:02:32 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -2058,7 +2058,11 @@ int main(int argc, char * const argv[])
 
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
+#endif
 #endif
 
       logStartingEnv();
