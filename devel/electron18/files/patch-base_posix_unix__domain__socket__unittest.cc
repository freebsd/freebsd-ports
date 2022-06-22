--- base/posix/unix_domain_socket_unittest.cc.orig	2022-05-19 03:45:15 UTC
+++ base/posix/unix_domain_socket_unittest.cc
@@ -10,6 +10,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/bind.h"
 #include "base/callback_helpers.h"
 #include "base/files/file_util.h"
