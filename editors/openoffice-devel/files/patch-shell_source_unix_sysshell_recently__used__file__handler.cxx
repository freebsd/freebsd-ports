--- shell/source/unix/sysshell/recently_used_file_handler.cxx.orig	2014-09-19 18:15:07 UTC
+++ shell/source/unix/sysshell/recently_used_file_handler.cxx
@@ -40,6 +40,7 @@
 #include <algorithm>
 #include <functional>
 #include <string.h>
+#include <time.h>
 
 namespace /* private */ {
     //########################################   
