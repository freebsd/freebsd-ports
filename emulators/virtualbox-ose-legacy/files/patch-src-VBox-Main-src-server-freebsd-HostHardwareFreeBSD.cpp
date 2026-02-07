--- src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp.orig	2020-05-13 19:44:10 UTC
+++ src/VBox/Main/src-server/freebsd/HostHardwareFreeBSD.cpp
@@ -253,8 +253,9 @@ static int getDVDInfoFromCAM(DriveInfoList *pList, boo
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
