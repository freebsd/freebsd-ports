--- cprime/filefunc.cpp.orig	2021-04-18 18:37:03 UTC
+++ cprime/filefunc.cpp
@@ -34,7 +34,8 @@
 #include <libgen.h>
 #include <sys/types.h>
 #include <sys/statvfs.h>
-#include <sys/statfs.h>
+// #include <sys/statfs.h>
+#include <errno.h>
 #include <unistd.h>
 
 #include "filefunc.h"
