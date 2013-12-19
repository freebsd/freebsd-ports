--- src/server_poll/daemon_fork.cpp.orig
+++ src/server_poll/daemon_fork.cpp
@@ -20,10 +20,12 @@
 #include <cassert>
 #include <cstring>
 #include <cerrno>
-#include <glib/gmain.h>
+#include <glib.h>
+#include <sys/types.h>
 #include <sys/socket.h>
-#include <sys/stat.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
+#include <sys/stat.h>
 
 #include "daemon_fork.h"
 #include "irc/irc.h"
