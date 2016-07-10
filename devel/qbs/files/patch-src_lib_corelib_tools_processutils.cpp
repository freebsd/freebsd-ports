--- src/lib/corelib/tools/processutils.cpp.orig	2016-07-08 11:54:19.708701000 +0200
+++ src/lib/corelib/tools/processutils.cpp	2016-07-08 12:06:40.098340000 +0200
@@ -42,12 +42,12 @@
 #   include <cstdio>
 #elif defined(Q_OS_BSD4)
 # include <QFile>
-# if !defined(Q_OS_NETBSD)
-#   include <sys/user.h>
-# endif
 #   include <sys/cdefs.h>
 #   include <sys/param.h>
 #   include <sys/sysctl.h>
+# if !defined(Q_OS_NETBSD)
+#   include <sys/user.h>
+# endif
 #else
 #   error Missing implementation of processNameByPid for this platform.
 #endif
