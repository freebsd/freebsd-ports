--- aegrep/main.cc.orig	2012-12-04 02:03:33 UTC
+++ aegrep/main.cc
@@ -32,6 +32,9 @@
 
 #include <aegrep/arglex3.h>
 
+#include <sys/types.h>
+#include <sys/wait.h>
+
 
 static void
 grep_usage(void)
