--- src/foreign/flann/util/logger.h.orig	2013-01-18 09:26:49.000000000 +0200
+++ src/foreign/flann/util/logger.h	2013-01-18 09:26:20.000000000 +0200
@@ -32,6 +32,7 @@
 #define LOGGER_H
 
 #include <cstdio>
+#include <stdarg.h>
 #include "flann/general.h"
 
 namespace flann
