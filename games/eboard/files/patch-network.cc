--- network.cc.orig	Mon Mar 25 10:19:21 2002
+++ network.cc	Mon Mar 25 10:19:52 2002
@@ -26,6 +26,7 @@
 
 
 #include <iostream.h>
+#include <arpa/inet.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/wait.h>
