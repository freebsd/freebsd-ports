Re-enable tray icon for KDE4 until KDE5 is in the ports tree. Mpris plugin
works, but tray icon might be wanted to minimize app in the time being.

--- src/GMPlayerManager.cpp.orig	2016-10-22 17:13:46 UTC
+++ src/GMPlayerManager.cpp
@@ -741,7 +741,7 @@ FXint GMPlayerManager::run(int& argc,cha
     // KDE5 comes with mpris plugin on the toolbar, no need for
     // tray icon
     if (gm_desktop_session()==DESKTOP_SESSION_KDE_PLASMA) {
-      preferences.gui_tray_icon_disabled=true;
+      preferences.gui_tray_icon_disabled=false;
       }
 
     /// Grab Media Player Keys
