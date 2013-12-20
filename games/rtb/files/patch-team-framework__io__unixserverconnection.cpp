--- team-framework/io/unixserverconnection.cpp.orig
+++ team-framework/io/unixserverconnection.cpp
@@ -41,6 +41,9 @@
 //IPC
 #include <fcntl.h>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 /**
  * Namespace
  */
