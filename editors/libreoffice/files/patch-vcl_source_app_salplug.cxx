--- vcl/source/app/salplug.cxx.orig	2022-05-12 13:26:05 UTC
+++ vcl/source/app/salplug.cxx
@@ -202,6 +202,7 @@ const char* const* autodetect_plugin_list()
 #if ENABLE_KF5
         "kf5",
 #endif
+        "qt5",
 #if ENABLE_GTK3_KDE5
         "gtk3_kde5",
 #endif
@@ -216,6 +217,7 @@ const char* const* autodetect_plugin_list()
 
     static const char* const pStandardFallbackList[] =
     {
+        "qt5",
 #if ENABLE_GTK3
         "gtk3",
 #endif
