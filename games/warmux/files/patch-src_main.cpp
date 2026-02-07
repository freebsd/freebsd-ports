--- src/main.cpp.orig	2011-04-28 19:03:06.000000000 +0000
+++ src/main.cpp
@@ -21,6 +21,7 @@
 
 #include <WARMUX_singleton.h>
 #include <getopt.h>
+#include <unistd.h>
 #ifndef WIN32
 # include <signal.h>
 #endif
