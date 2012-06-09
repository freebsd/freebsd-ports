--- ./libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp.orig	2012-01-02 19:32:23.000000000 -0500
+++ ./libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp	2012-05-14 20:28:25.000000000 -0400
@@ -53,6 +53,9 @@
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <unistd.h>
+#include <paths.h>
+#include <fcntl.h>
+#include <kvm.h>
 #endif
 #if defined(Q_OS_NETBSD)
 #include <sys/param.h>
