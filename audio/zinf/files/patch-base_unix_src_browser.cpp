--- base/unix/src/browser.cpp.orig	2003-09-16 20:34:54.000000000 +0300
+++ base/unix/src/browser.cpp
@@ -9,6 +9,7 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <string>
+#include <cstring>
 
 using namespace std;
 #include "browser.h"
