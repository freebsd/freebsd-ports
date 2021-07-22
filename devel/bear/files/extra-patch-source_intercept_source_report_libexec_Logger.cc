--- source/intercept/source/report/libexec/Logger.cc.orig	2021-07-22 21:19:02 UTC
+++ source/intercept/source/report/libexec/Logger.cc
@@ -20,6 +20,7 @@
 #include "report/libexec/Logger.h"
 
 #include <ctime>
+#define _WITH_DPRINTF
 #include <cstdio>
 #include <unistd.h>
 
