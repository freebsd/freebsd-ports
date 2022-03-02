--- src/highscore.cc.orig	2022-02-06 08:35:59 UTC
+++ src/highscore.cc
@@ -22,6 +22,7 @@
 
 #include <cstdio>
 #include <unistd.h>
+#include <sys/stat.h>
 
 #ifndef _WIN32
 #include <fcntl.h>
@@ -221,12 +222,12 @@ void hsc_init(void) {
         }
         else
         {
-            debugprintf(2, "could not open create the lock file, no write access to global hiscore directory\n", fname);
+            debugprintf(2, "could not open create the lock file, no write access to global hiscore directory\n", fname.c_str());
         }
     }
     else
     {
-        debugprintf(2, "could not open global highscore file %s\n", fname);
+        debugprintf(2, "could not open global highscore file %s\n", fname.c_str());
     }
 
 #else
