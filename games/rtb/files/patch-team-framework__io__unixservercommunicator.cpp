--- team-framework/io/unixservercommunicator.cpp.orig
+++ team-framework/io/unixservercommunicator.cpp
@@ -50,6 +50,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <unistd.h>
 
 /**
  * Namespace
