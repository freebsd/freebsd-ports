--- lib/aviplay/aviplay.cpp.orig	Tue Aug 28 21:53:40 2001
+++ lib/aviplay/aviplay.cpp	Tue Aug 28 21:53:43 2001
@@ -25,6 +25,7 @@
 #include "cpuinfo.h"
 #include "utils.h"
 #include "version.h"
+#include <pthread.h>
 
 //#include <iomanip>
 #include <iostream>
