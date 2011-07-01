--- src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp.orig	2011-05-16 12:33:46.000000000 -0400
+++ src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp	2011-06-24 16:03:37.000000000 -0400
@@ -35,6 +35,7 @@
 #include <iprt/string.h>
 
 #ifdef RT_OS_FREEBSD
+# include <sys/param.h>
 # include <sys/types.h>
 # include <sys/stat.h>
 # include <unistd.h>
@@ -186,11 +187,17 @@ static int getDVDInfoFromCAM(DriveInfoLi
         DeviceMatchPattern.pattern.device_pattern.target_id  = CAM_TARGET_WILDCARD;
         DeviceMatchPattern.pattern.device_pattern.target_lun = CAM_LUN_WILDCARD;
         DeviceMatchPattern.pattern.device_pattern.flags      = DEV_MATCH_INQUIRY;
-        DeviceMatchPattern.pattern.device_pattern.inq_pat.type = T_CDROM;
-        DeviceMatchPattern.pattern.device_pattern.inq_pat.media_type  = SIP_MEDIA_REMOVABLE | SIP_MEDIA_FIXED;
-        DeviceMatchPattern.pattern.device_pattern.inq_pat.vendor[0]   = '*'; /* Matches anything */
-        DeviceMatchPattern.pattern.device_pattern.inq_pat.product[0]  = '*'; /* Matches anything */
-        DeviceMatchPattern.pattern.device_pattern.inq_pat.revision[0] = '*'; /* Matches anything */
+#if __FreeBSD_version >= 900000
+#define INQ_PAT data.inq_pat
+#else
+#define INQ_PAT inq_pat
+#endif
+        DeviceMatchPattern.pattern.device_pattern.INQ_PAT.type = T_CDROM;
+        DeviceMatchPattern.pattern.device_pattern.INQ_PAT.media_type  = SIP_MEDIA_REMOVABLE | SIP_MEDIA_FIXED;
+        DeviceMatchPattern.pattern.device_pattern.INQ_PAT.vendor[0]   = '*'; /* Matches anything */
+        DeviceMatchPattern.pattern.device_pattern.INQ_PAT.product[0]  = '*'; /* Matches anything */
+        DeviceMatchPattern.pattern.device_pattern.INQ_PAT.revision[0] = '*'; /* Matches anything */
+#undef INQ_PAT
         DeviceCCB.cdm.num_patterns    = 1;
         DeviceCCB.cdm.pattern_buf_len = sizeof(struct dev_match_result);
         DeviceCCB.cdm.patterns        = &DeviceMatchPattern;
