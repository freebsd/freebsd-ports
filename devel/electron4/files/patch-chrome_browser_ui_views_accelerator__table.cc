--- chrome/browser/ui/views/accelerator_table.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/views/accelerator_table.cc
@@ -49,7 +49,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_S, ui::EF_PLATFORM_ACCELERATOR, IDC_SAVE_PAGE},
     {ui::VKEY_9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     {ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT},
@@ -79,7 +79,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD7, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_6},
     {ui::VKEY_8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
     {ui::VKEY_NUMPAD8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     {ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1},
@@ -121,7 +121,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_F11, ui::EF_NONE, IDC_FULLSCREEN},
 
   // Platform-specific key maps.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK},
     {ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD},
     {ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME},
