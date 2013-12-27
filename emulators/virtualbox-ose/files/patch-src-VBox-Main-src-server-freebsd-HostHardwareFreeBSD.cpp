--- src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp.orig	2013-11-29 14:24:12.000000000 -0500
+++ src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp	2013-12-13 18:03:02.000000000 -0500
@@ -39,6 +39,7 @@
 # include <sys/stat.h>
 # include <unistd.h>
 # include <sys/ioctl.h>
+# include <stdio.h>
 # include <fcntl.h>
 # include <cam/cam.h>
 # include <cam/cam_ccb.h>
@@ -250,7 +251,7 @@
                         PeriphMatchPattern.pattern.periph_pattern.path_id    = paMatches[i].result.device_result.path_id;
                         PeriphMatchPattern.pattern.periph_pattern.target_id  = paMatches[i].result.device_result.target_id;
                         PeriphMatchPattern.pattern.periph_pattern.target_lun = paMatches[i].result.device_result.target_lun;
-                        PeriphMatchPattern.pattern.periph_pattern.flags      = PERIPH_MATCH_PATH | PERIPH_MATCH_TARGET | PERIPH_MATCH_LUN;
+                        PeriphMatchPattern.pattern.periph_pattern.flags      = static_cast<periph_pattern_flags>(PERIPH_MATCH_PATH | PERIPH_MATCH_TARGET | PERIPH_MATCH_LUN);
                         PeriphCCB.cdm.num_patterns    = 1;
                         PeriphCCB.cdm.pattern_buf_len = sizeof(struct dev_match_result);
                         PeriphCCB.cdm.patterns        = &PeriphMatchPattern;
