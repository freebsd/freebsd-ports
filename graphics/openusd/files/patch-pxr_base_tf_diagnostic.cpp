--- pxr/base/tf/diagnostic.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/tf/diagnostic.cpp
@@ -20,6 +20,7 @@
 #include <cstdio>
 #include <stdexcept>
 #include <csignal>
+#include <unistd.h>
 
 using std::string;
 
