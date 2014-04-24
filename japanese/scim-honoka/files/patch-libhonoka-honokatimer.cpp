--- libhonoka/honokatimer.cpp.orig
+++ libhonoka/honokatimer.cpp
@@ -21,6 +21,7 @@
 #include "honokatimer.h"
 #include <signal.h>
 #include <sys/wait.h>
+#include <unistd.h>
 
 using namespace Honoka;
 
