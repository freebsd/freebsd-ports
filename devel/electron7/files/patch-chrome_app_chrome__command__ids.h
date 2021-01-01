--- chrome/app/chrome_command_ids.h.orig	2019-12-12 12:39:04 UTC
+++ chrome/app/chrome_command_ids.h
@@ -63,7 +63,7 @@
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_2 34049
 #define IDC_VISIT_DESKTOP_OF_LRU_USER_3 34050
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #define IDC_USE_SYSTEM_TITLE_BAR        34051
 #define IDC_RESTORE_WINDOW              34052
 #endif
