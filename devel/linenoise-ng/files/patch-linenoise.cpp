--- src/linenoise.cpp	2015-11-25 01:30:22.000000000 -0800
+++ /tmp/linenoise.cpp	2017-02-17 10:10:37.354285000 -0800
@@ -105,6 +105,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <cctype>
@@ -3093,10 +3094,17 @@
 /* Save the history in the specified file. On success 0 is returned
  * otherwise -1 is returned. */
 int linenoiseHistorySave(const char* filename) {
+#ifndef _WIN32
+  mode_t old_umask = umask(S_IXUSR|S_IRWXG|S_IRWXO);
+#endif
     FILE* fp = fopen(filename, "wt");
     if (fp == NULL) {
         return -1;
     }
+#ifndef _WIN32
+  umask(old_umask);
+  chmod(filename,S_IRUSR|S_IWUSR);
+#endif
 
     for (int j = 0; j < historyLen; ++j) {
         if (history[j][0] != '\0') {
