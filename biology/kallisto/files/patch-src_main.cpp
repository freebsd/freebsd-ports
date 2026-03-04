--- src/main.cpp.orig	2026-01-20 17:34:25 UTC
+++ src/main.cpp
@@ -1,6 +1,7 @@
 #include <getopt.h>
 #include <sys/stat.h>
 #include <time.h>
+#include <unistd.h>
 
 #include <CompactedDBG.hpp>
 #include <algorithm>
