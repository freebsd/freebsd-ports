--- sql/wsrep_utils.cc.orig	2017-06-12 10:31:29 UTC
+++ sql/wsrep_utils.cc
@@ -26,6 +26,7 @@
 #include <sql_class.h>
 #include <socket_connection.h>
 
+#include <signal.h>
 #include <spawn.h>    // posix_spawn()
 #include <unistd.h>   // pipe()
 #include <errno.h>    // errno
