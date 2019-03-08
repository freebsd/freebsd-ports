--- src/cpp/session/SessionMain.cpp.orig	2019-02-18 01:05:52 UTC
+++ src/cpp/session/SessionMain.cpp
@@ -1620,8 +1620,12 @@ int main (int argc, char * const argv[])
       
       // move to own process group
 #ifndef _WIN32
+#if defined(__FreeBSD__)
+      ::setpgrp(0, 0);
+#else
       ::setpgrp();
 #endif
+#endif
 
       // get main thread id (used to distinguish forks which occur
       // from the main thread vs. child threads)
