--- base/posix/unix_domain_socket_unittest.cc.orig	2024-06-18 21:43:17 UTC
+++ base/posix/unix_domain_socket_unittest.cc
@@ -15,6 +15,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/files/file_util.h"
 #include "base/files/scoped_file.h"
 #include "base/functional/bind.h"
