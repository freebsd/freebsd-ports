--- src/irc/dcc.cpp.orig
+++ src/irc/dcc.cpp
@@ -17,12 +17,13 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
-#include <errno.h>
-#include <string.h>
+#include <cerrno>
+#include <cstring>
 #include <sys/types.h>
-#include <netinet/in.h>
+#include <unistd.h>
 
 #include "dcc.h"
 #include "nick.h"
