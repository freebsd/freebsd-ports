--- chrome/browser/ui/views/accelerator_table.cc.orig	2019-09-10 11:13:43 UTC
+++ chrome/browser/ui/views/accelerator_table.cc
@@ -50,7 +50,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_S, ui::EF_PLATFORM_ACCELERATOR, IDC_SAVE_PAGE},
     {ui::VKEY_9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     {ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT},
@@ -80,7 +80,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD7, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_6},
     {ui::VKEY_8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
     {ui::VKEY_NUMPAD8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     {ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1},
@@ -98,7 +98,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_8, ui::EF_ALT_DOWN, IDC_SELECT_TAB_7},
     {ui::VKEY_NUMPAD8, ui::EF_ALT_DOWN, IDC_SELECT_TAB_7},
     {ui::VKEY_BROWSER_FAVORITES, ui::EF_NONE, IDC_SHOW_BOOKMARK_BAR},
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX || OS_BSD) && !OS_CHROMEOS
     {ui::VKEY_B, ui::EF_SHIFT_DOWN | ui::EF_PLATFORM_ACCELERATOR,
      IDC_SHOW_BOOKMARK_BAR},
     {ui::VKEY_OEM_MINUS, ui::EF_PLATFORM_ACCELERATOR, IDC_ZOOM_MINUS},
@@ -124,14 +124,14 @@ const AcceleratorMapping kAcceleratorMap[] = {
      IDC_SHOW_AVATAR_MENU},
 
   // Platform-specific key maps.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK},
     {ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD},
     {ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_NONE, IDC_RELOAD},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_CONTROL_DOWN, IDC_RELOAD_BYPASSING_CACHE},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_SHIFT_DOWN, IDC_RELOAD_BYPASSING_CACHE},
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
     // On Chrome OS, VKEY_BROWSER_SEARCH is handled in Ash.
