--- src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp.orig	2015-04-14 15:41:25.000000000 -0400
+++ src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp	2015-04-14 18:25:23.156536000 -0400
@@ -251,8 +251,9 @@
                         PeriphMatchPattern.pattern.periph_pattern.path_id    = paMatches[i].result.device_result.path_id;
                         PeriphMatchPattern.pattern.periph_pattern.target_id  = paMatches[i].result.device_result.target_id;
                         PeriphMatchPattern.pattern.periph_pattern.target_lun = paMatches[i].result.device_result.target_lun;
-                        PeriphMatchPattern.pattern.periph_pattern.flags      = PERIPH_MATCH_PATH | PERIPH_MATCH_TARGET |
-                                                                               PERIPH_MATCH_LUN;
+                        PeriphMatchPattern.pattern.periph_pattern.flags      = static_cast<periph_pattern_flags>
+                                                                               (PERIPH_MATCH_PATH | PERIPH_MATCH_TARGET |
+                                                                               PERIPH_MATCH_LUN);
                         PeriphCCB.cdm.num_patterns    = 1;
                         PeriphCCB.cdm.pattern_buf_len = sizeof(struct dev_match_result);
                         PeriphCCB.cdm.patterns        = &PeriphMatchPattern;
