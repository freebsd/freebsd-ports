--- base/posix/unix_domain_socket_unittest.cc.orig	2026-01-07 00:52:53 UTC
+++ base/posix/unix_domain_socket_unittest.cc
@@ -15,6 +15,8 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#include <signal.h>
+
 #include "base/files/scoped_file.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback_helpers.h"
