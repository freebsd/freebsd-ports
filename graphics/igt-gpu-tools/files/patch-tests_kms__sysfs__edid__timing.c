--- tests/kms_sysfs_edid_timing.c.orig	2022-08-31 20:00:01 UTC
+++ tests/kms_sysfs_edid_timing.c
@@ -26,6 +26,10 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+#include <limits.h>
+#endif
+
 #define THRESHOLD_PER_CONNECTOR		150
 #define THRESHOLD_PER_CONNECTOR_MEAN	140
 #define THRESHOLD_ALL_CONNECTORS_MEAN	100
