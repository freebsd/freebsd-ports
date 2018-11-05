--- Robots/seek_and_destroy/seek_and_destroy.cc.orig	2018-10-20 20:20:40 UTC
+++ Robots/seek_and_destroy/seek_and_destroy.cc
@@ -6,6 +6,7 @@
 #include <unistd.h>
 #include <signal.h>
 #include <stdlib.h>
+#include <cstring>
 
 #ifdef TIME_WITH_SYS_TIME 
 # include <sys/time.h>
