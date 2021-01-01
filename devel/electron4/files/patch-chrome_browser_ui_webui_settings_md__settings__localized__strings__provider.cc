--- chrome/browser/ui/webui/settings/md_settings_localized_strings_provider.cc.orig	2019-03-15 06:37:08 UTC
+++ chrome/browser/ui/webui/settings/md_settings_localized_strings_provider.cc
@@ -442,7 +442,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
     {"enterCustomWebAddress", IDS_SETTINGS_ENTER_CUSTOM_WEB_ADDRESS},
     {"homeButtonDisabled", IDS_SETTINGS_HOME_BUTTON_DISABLED},
     {"themes", IDS_SETTINGS_THEMES},
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     {"systemTheme", IDS_SETTINGS_SYSTEM_THEME},
     {"useSystemTheme", IDS_SETTINGS_USE_SYSTEM_THEME},
     {"classicTheme", IDS_SETTINGS_CLASSIC_THEME},
@@ -460,7 +460,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
     {"openWallpaperApp", IDS_SETTINGS_OPEN_WALLPAPER_APP},
     {"setWallpaper", IDS_SETTINGS_SET_WALLPAPER},
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
     {"showWindowDecorations", IDS_SHOW_WINDOW_DECORATIONS},
 #endif
 #if defined(OS_MACOSX)
