--- team-framework/io/unixclientcommunicator.cpp.orig
+++ team-framework/io/unixclientcommunicator.cpp
@@ -46,6 +46,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <unistd.h>
 
 /**
  * Namespace
