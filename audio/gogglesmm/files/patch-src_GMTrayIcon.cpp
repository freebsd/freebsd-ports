Add pseudo transparency to the tray icon

--- src/GMTrayIcon.cpp.orig	2016-10-22 17:13:46 UTC
+++ src/GMTrayIcon.cpp
@@ -81,17 +81,17 @@ void GMTrayIcon::updateIcon() {
 
     /// Update
     if (size<=16) {
-      icon = new FXPNGIcon(getApp(),gogglesmm_16_png,0,opaque ? IMAGE_OPAQUE : 0);
+      icon = new FXPNGIcon(getApp(),gogglesmm_16_png,0,IMAGE_ALPHAGUESS);
       icon->setVisual(getVisual());
       if (size!=16) icon->scale(size,size,FOX_SCALE_BEST);
       }
     else {
-      icon = new FXPNGIcon(getApp(),gogglesmm_32_png,0,opaque ? IMAGE_OPAQUE : 0);
+      icon = new FXPNGIcon(getApp(),gogglesmm_32_png,0,IMAGE_ALPHAGUESS);
       icon->setVisual(getVisual());
       if (size!=32) icon->scale(size,size,FOX_SCALE_BEST);
       }
 
-    icon->blend(GMPlayerManager::instance()->getPreferences().gui_tray_color);
+    //icon->blend(GMPlayerManager::instance()->getPreferences().gui_tray_color);
     icon->create();
 
     // Mark Dirty
@@ -230,13 +230,8 @@ void GMTrayIcon::create(){
 
 void GMTrayIcon::dock() {
   if (findSystemTray()){
-    FXuint trayid = getTrayVisual();
-    if (trayid) {
-      if (trayid!=XVisualIDFromVisual((Visual*)getVisual()->getVisual()))
-        opaque=true;
-      else
-        opaque=false;
-      }
+
+    opaque=false;
 
     if (!opaque) {
       /// Don't draw the background
@@ -276,16 +271,16 @@ long GMTrayIcon::onConfigure(FXObject*,F
 
   if (icon==nullptr) {
     if (size<=16) {
-      icon = new FXPNGIcon(getApp(),gogglesmm_16_png,0,opaque ? IMAGE_OPAQUE : 0);
+      icon = new FXPNGIcon(getApp(),gogglesmm_16_png,0,IMAGE_ALPHAGUESS);
       icon->setVisual(getVisual());
       if (size!=16) icon->scale(size,size,FOX_SCALE_BEST);
       }
     else {
-      icon = new FXPNGIcon(getApp(),gogglesmm_32_png,0,opaque ? IMAGE_OPAQUE : 0);
+      icon = new FXPNGIcon(getApp(),gogglesmm_32_png,0,IMAGE_ALPHAGUESS);
       icon->setVisual(getVisual());
       if (size!=32) icon->scale(size,size,FOX_SCALE_BEST);
       }
-    icon->blend(GMPlayerManager::instance()->getPreferences().gui_tray_color);
+    //icon->blend(GMPlayerManager::instance()->getPreferences().gui_tray_color);
     icon->create();
     }
   return 1;
