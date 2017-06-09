--- util/log.hpp.orig	2014-02-09 11:52:42 UTC
+++ util/log.hpp
@@ -42,6 +42,7 @@
 #include <fcntl.h>
 #include <iostream>
 #include <string>
+#include <string.h>
 #include <syslog.h>
 
 #define UTIL_MAX_ERROR_SIZE 2048
