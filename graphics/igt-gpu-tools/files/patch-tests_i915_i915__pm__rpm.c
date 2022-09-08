--- tests/i915/i915_pm_rpm.c.orig	2022-08-31 20:00:01 UTC
+++ tests/i915/i915_pm_rpm.c
@@ -40,8 +40,10 @@
 #include <sys/mman.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <linux/i2c.h>
 #include <linux/i2c-dev.h>
+#endif
 
 #include <drm.h>
 
@@ -53,6 +55,17 @@
 #include "igt_debugfs.h"
 #include "igt_device.h"
 #include "igt_edid.h"
+
+#ifdef __FreeBSD__
+#include <limits.h>
+#include <dev/iicbus/iic.h>
+
+#define	I2C_RDWR		I2CRDWR
+#define	I2C_M_RD		IIC_M_RD
+#define	i2c_msg			iic_msg
+#define	i2c_rdwr_ioctl_data	iic_rdwr_data
+#define	addr			slave
+#endif
 
 #define MSR_PC8_RES	0x630
 #define MSR_PC9_RES	0x631
