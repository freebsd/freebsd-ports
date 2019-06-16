--- folly/Subprocess.cpp.orig	2019-06-16 07:47:17 UTC
+++ folly/Subprocess.cpp
@@ -24,6 +24,7 @@
 #include <sys/prctl.h>
 #endif
 #include <fcntl.h>
+#include <unistd.h>
 
 #include <algorithm>
 #include <array>
@@ -394,6 +395,7 @@ void Subprocess::spawnInternal(
     envHolder = cloneStrings(*env);
     envVec = const_cast<char**>(envHolder.get());
   } else {
+    extern char **environ;
     envVec = environ;
   }
 
@@ -557,7 +559,7 @@ int Subprocess::prepareChild(
 #endif
 
   if (options.processGroupLeader_) {
-    if (setpgrp() == -1) {
+    if (setpgrp(0, 0) == -1) {
       return errno;
     }
   }
