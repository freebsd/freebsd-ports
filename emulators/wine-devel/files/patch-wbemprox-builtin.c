commit 2d35c22a51fb7cfc611045537cea06e1118cabd9
Author: Gerald Pfeifer <gerald@pfeifer.com>
Date:   Sat Aug 18 16:52:27 2018 +0000

    Fix the build on FreeBSD by including sys/socket.h.

--- UTC
diff --git a/dlls/wbemprox/builtin.c b/dlls/wbemprox/builtin.c
index 72c6b4e933..3b8b43e868 100644
--- dlls/wbemprox/builtin.c
+++ dlls/wbemprox/builtin.c
@@ -26,6 +26,9 @@
 #ifdef HAVE_UNISTD_H
 # include <unistd.h>
 #endif
+#ifdef HAVE_SYS_SOCKET_H
+# include <sys/socket.h>
+#endif
 #ifdef HAVE_ARPA_INET_H
 # include <arpa/inet.h>
 #endif
