--- libs/pbd/ftw.cc.orig	2012-05-15 13:18:56 UTC
+++ libs/pbd/ftw.cc
@@ -33,7 +33,7 @@
 #include <sys/types.h> /* Because fts(3) says so */
 #include <sys/stat.h>
 #include <fts.h>
-#include <alloca.h>
+#include <cstdlib>
 
 #include <unistd.h> /* We want strcpy */
 
