--- table-update.cpp.orig	2018-05-21 12:32:01 UTC
+++ table-update.cpp
@@ -1,7 +1,7 @@
 #include "gcin.h"
 #include <sys/stat.h>
 #if UNIX
-#include <linux/limits.h>
+#include <sys/limits.h>
 #endif
 
 void update_table_file(char *name, int version)
