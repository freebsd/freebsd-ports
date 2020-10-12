--- src/intel/vulkan/anv_device.c.orig	2020-09-28 22:52:12 UTC
+++ src/intel/vulkan/anv_device.c
@@ -48,6 +48,10 @@
 
 #include "genxml/gen7_pack.h"
 
+#if DETECT_OS_FREEBSD
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+#endif
+
 static const char anv_dri_options_xml[] =
 DRI_CONF_BEGIN
    DRI_CONF_SECTION_PERFORMANCE
