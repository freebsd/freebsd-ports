- Use setpgrp(0,0) on FreeBSD (different signature than Linux)

--- src/cpp/session/SessionMain.cpp.orig	2025-10-20 20:09:32 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -2187,7 +2187,11 @@ int main(int argc, char * const argv[])
 
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
+#endif
 #endif
 
       logStartingEnv();
