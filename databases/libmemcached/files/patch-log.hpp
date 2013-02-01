--- util/log.hpp.orig        2012-04-22 19:10:08.624721461 +0200
+++ util/log.hpp     2012-04-22 19:11:43.651275813 +0200
@@ -27,6 +27,7 @@
 #include <fcntl.h>
 #include <iostream>
 #include <string>
+#include <string.h>
 #include <syslog.h>

 #define UTIL_MAX_ERROR_SIZE 2048
