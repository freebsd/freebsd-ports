--- src/editlog.c.orig	2020-04-29 13:15:29 UTC
+++ src/editlog.c
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include "background_process.h"
 #include "checklogfile.h"
