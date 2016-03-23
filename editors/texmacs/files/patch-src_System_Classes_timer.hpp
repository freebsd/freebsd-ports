--- src/System/Classes/timer.hpp.orig	2013-11-03 23:09:43 UTC
+++ src/System/Classes/timer.hpp
@@ -14,10 +14,7 @@
 #include "string.hpp"
 #include "tm_configure.hpp"
 
-#ifndef HAVE_TIME_T
-#define HAVE_TIME_T
-typedef long time_t;
-#endif
+#include <time.h>
 
 #ifdef OS_SUN
 #include <sys/types.h>
