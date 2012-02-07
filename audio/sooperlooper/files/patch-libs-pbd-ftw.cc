--- libs/pbd/ftw.cc-dist	2012-01-08 20:15:45.901151819 +0100
+++ libs/pbd/ftw.cc	2012-01-08 20:15:58.904148109 +0100
@@ -33,7 +33,7 @@
 #include <sys/types.h> /* Because fts(3) says so */
 #include <sys/stat.h>
 #include <fts.h>
-#include <alloca.h>
+#include <stdlib.h>
 
 #include <unistd.h> /* We want strcpy */
 
