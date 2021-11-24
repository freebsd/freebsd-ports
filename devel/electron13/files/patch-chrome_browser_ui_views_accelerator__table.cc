--- chrome/browser/ui/views/accelerator_table.cc.orig	2021-07-15 19:13:34 UTC
+++ chrome/browser/ui/views/accelerator_table.cc
@@ -62,7 +62,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD9, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_LAST_TAB},
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     {ui::VKEY_9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NUMPAD9, ui::EF_ALT_DOWN, IDC_SELECT_LAST_TAB},
     {ui::VKEY_NEXT, ui::EF_CONTROL_DOWN | ui::EF_SHIFT_DOWN, IDC_MOVE_TAB_NEXT},
@@ -94,7 +94,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_NUMPAD8, ui::EF_PLATFORM_ACCELERATOR, IDC_SELECT_TAB_7},
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     {ui::VKEY_1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_NUMPAD1, ui::EF_ALT_DOWN, IDC_SELECT_TAB_0},
     {ui::VKEY_2, ui::EF_ALT_DOWN, IDC_SELECT_TAB_1},
@@ -112,7 +112,7 @@ const AcceleratorMapping kAcceleratorMap[] = {
     {ui::VKEY_8, ui::EF_ALT_DOWN, IDC_SELECT_TAB_7},
     {ui::VKEY_NUMPAD8, ui::EF_ALT_DOWN, IDC_SELECT_TAB_7},
     {ui::VKEY_BROWSER_FAVORITES, ui::EF_NONE, IDC_SHOW_BOOKMARK_BAR},
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX || OS_BSD) && !OS_CHROMEOS
     {ui::VKEY_B, ui::EF_SHIFT_DOWN | ui::EF_PLATFORM_ACCELERATOR,
      IDC_SHOW_BOOKMARK_BAR},
     {ui::VKEY_OEM_MINUS, ui::EF_PLATFORM_ACCELERATOR, IDC_ZOOM_MINUS},
@@ -138,14 +138,14 @@ const AcceleratorMapping kAcceleratorMap[] = {
      IDC_SHOW_AVATAR_MENU},
 
 // Platform-specific key maps.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {ui::VKEY_BROWSER_BACK, ui::EF_NONE, IDC_BACK},
     {ui::VKEY_BROWSER_FORWARD, ui::EF_NONE, IDC_FORWARD},
     {ui::VKEY_BROWSER_HOME, ui::EF_NONE, IDC_HOME},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_NONE, IDC_RELOAD},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_CONTROL_DOWN, IDC_RELOAD_BYPASSING_CACHE},
     {ui::VKEY_BROWSER_REFRESH, ui::EF_SHIFT_DOWN, IDC_RELOAD_BYPASSING_CACHE},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
     // On Chrome OS, VKEY_BROWSER_SEARCH is handled in Ash.
