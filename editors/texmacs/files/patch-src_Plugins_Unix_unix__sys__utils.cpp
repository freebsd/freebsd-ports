--- src/Plugins/Unix/unix_sys_utils.cpp.orig	2015-12-01 15:10:21 UTC
+++ src/Plugins/Unix/unix_sys_utils.cpp
@@ -17,6 +17,7 @@
 #include <spawn.h>
 #include <unistd.h>
 #include <sys/wait.h>
+#include <pthread.h>
 
 // for thread safe strings
 #include <string>
