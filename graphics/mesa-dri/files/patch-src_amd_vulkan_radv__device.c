--- src/amd/vulkan/radv_device.c.orig	2020-09-28 22:52:10 UTC
+++ src/amd/vulkan/radv_device.c
@@ -56,6 +56,10 @@
 #include "compiler/glsl_types.h"
 #include "util/driconf.h"
 
+#if DETECT_OS_FREEBSD
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+#endif
+
 static struct radv_timeline_point *
 radv_timeline_find_point_at_least_locked(struct radv_device *device,
                                          struct radv_timeline *timeline,
