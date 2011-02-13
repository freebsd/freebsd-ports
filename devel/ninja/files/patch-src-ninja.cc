--- src/ninja.orig	2011-02-10 17:21:11.000000000 +0200
+++ src/ninja.cc	2011-02-10 17:21:43.000000000 +0200
@@ -20,6 +20,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
+#if defined(__APPLE__) || defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <sys/types.h>
 
 #include "build.h"
@@ -64,6 +67,7 @@ void usage(const BuildConfig& config) {
 int GuessParallelism() {
   int processors = 0;
 
+#if defined(linux)
   const char kProcessorPrefix[] = "processor\t";
   char buf[16 << 10];
   FILE* f = fopen("/proc/cpuinfo", "r");
@@ -74,6 +78,12 @@ int GuessParallelism() {
       ++processors;
   }
   fclose(f);
+#elif defined(__APPLE__) || defined(__FreeBSD__)
+  size_t procSize = sizeof(processors);
+  int name[] = {CTL_HW, HW_NCPU};
+  if (sysctl(name, sizeof(name) / sizeof(int), &processors, &procSize, NULL, 0))
+    return 2;
+#endif
 
   switch (processors) {
   case 0:
