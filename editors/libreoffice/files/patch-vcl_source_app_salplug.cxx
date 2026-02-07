--- vcl/source/app/salplug.cxx.orig	2024-10-27 12:32:22 UTC
+++ vcl/source/app/salplug.cxx
@@ -184,6 +184,9 @@ const char* const* autodetect_plugin_list()
 #if ENABLE_KF5
         "kf5",
 #endif
+#if ENABLE_QT5
+        "qt5",
+#endif
 #if ENABLE_GTK3_KDE5
         "gtk3_kde5",
 #endif
@@ -201,9 +204,15 @@ const char* const* autodetect_plugin_list()
 #if ENABLE_KF6
         "kf6",
 #endif
+#if ENABLE_QT6
+        "qt6",
+#endif
 #if ENABLE_KF5
         "kf5",
 #endif
+#if ENABLE_QT5
+        "qt5",
+#endif
 #if ENABLE_GTK3_KDE5
         "gtk3_kde5",
 #endif
@@ -218,6 +227,15 @@ const char* const* autodetect_plugin_list()
 
     static const char* const pStandardFallbackList[] =
     {
+#if ENABLE_QT6
+        "qt6",
+#endif
+#if ENABLE_QT5
+        "qt5",
+#endif
+#if ENABLE_GTK4
+        "gtk4",
+#endif
 #if ENABLE_GTK3
         "gtk3",
 #endif
