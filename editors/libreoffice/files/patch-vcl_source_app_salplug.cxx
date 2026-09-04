--- vcl/source/app/salplug.cxx.orig	2026-06-16 11:40:38 UTC
+++ vcl/source/app/salplug.cxx
@@ -184,8 +184,14 @@ std::vector<OUString> autodetect_plugin_list()
         if (eDesktop == DesktopType::Plasma6)
             aPlugins.push_back(u"kf6"_ustr);
 #endif
+#if ENABLE_QT6
+        aPlugins.push_back(u"qt6"_ustr);
+#endif
 #if ENABLE_KF5
         aPlugins.push_back(u"kf5"_ustr);
+#endif
+#if ENABLE_QT5
+        aPlugins.push_back(u"qt5"_ustr);
 #endif
 #if ENABLE_GTK3_KDE5
         aPlugins.push_back(u"gtk3_kde5"_ustr);
