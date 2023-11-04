--- src/main.cpp.orig	2023-11-02 11:38:09 UTC
+++ src/main.cpp
@@ -11,6 +11,7 @@
 #include <limits>
 
 #include <cstdio>
+#include <unistd.h>	// rmdir()
 
 #include "common.h"
 #include "ProcessReads.h"
