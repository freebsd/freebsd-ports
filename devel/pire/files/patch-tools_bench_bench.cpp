--- tools/bench/bench.cpp.orig	2010-11-16 23:42:09.000000000 +0000
+++ tools/bench/bench.cpp
@@ -23,6 +23,7 @@
 
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <sys/time.h>
