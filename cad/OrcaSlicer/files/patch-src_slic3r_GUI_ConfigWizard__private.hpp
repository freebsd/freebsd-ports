--- src/slic3r/GUI/ConfigWizard_private.hpp.orig	2025-03-07 08:28:42 UTC
+++ src/slic3r/GUI/ConfigWizard_private.hpp
@@ -605,7 +605,7 @@
     bool apply_config(AppConfig *app_config, PresetBundle *preset_bundle, const PresetUpdater *updater, bool& apply_keeped_changes);
     // #ys_FIXME_alise
     void update_presets_in_config(const std::string& section, const std::string& alias_key, bool add);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     void perform_desktop_integration() const;
 #endif
     bool check_fff_selected();        // Used to decide whether to display Filaments page
