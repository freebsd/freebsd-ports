--- vcl/source/app/salplug.cxx.orig	2020-05-27 12:17:53 UTC
+++ vcl/source/app/salplug.cxx
@@ -152,6 +152,7 @@ SalInstance* autodetect_plugin()
 #if ENABLE_KF5
         "kf5",
 #endif
+        "qt5",
 #if ENABLE_GTK3_KDE5
         "gtk3_kde5",
 #endif
@@ -160,7 +161,7 @@ SalInstance* autodetect_plugin()
 
     static const char* const pStandardFallbackList[] =
     {
-        "gtk3", "gen", nullptr
+        "gtk3", "qt5", "gen", nullptr
     };
 
 #ifdef HEADLESS_VCLPLUG
