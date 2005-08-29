--- src/lib/Object.cpp.orig	Mon Aug 29 02:11:16 2005
+++ src/lib/Object.cpp	Mon Aug 29 02:11:39 2005
@@ -25,6 +25,7 @@
 #include "Object.h"
 #include "config.h"
 
+#include <stdio.h>
 #include <pthread.h>
 
 #ifdef WIN32
