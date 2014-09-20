--- aegrep/main.cc.orig	2014-08-02 11:30:25.351342791 +0000
+++ aegrep/main.cc	2014-08-02 11:30:52.520341498 +0000
@@ -32,6 +32,9 @@
 
 #include <aegrep/arglex3.h>
 
+#include <sys/types.h>
+#include <sys/wait.h>
+
 
 static void
 grep_usage(void)
