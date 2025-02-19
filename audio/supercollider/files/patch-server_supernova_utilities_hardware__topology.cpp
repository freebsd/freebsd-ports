--- server/supernova/utilities/hardware_topology.cpp.orig	2025-02-20 15:13:49 UTC
+++ server/supernova/utilities/hardware_topology.cpp
@@ -20,6 +20,7 @@
 #    include <windows.h>
 #    include <malloc.h>
 #elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#    include <sys/types.h>
 #    include <sys/sysctl.h>
 #    include <errno.h>
 #else /* Linux */
