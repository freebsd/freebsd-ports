--- src/slic3r/GUI/Plater.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -24,7 +24,7 @@
 
 #include <cstddef>
 #include <algorithm>
-#include <nanosvgrast.h>
+#include <libnanosvg/nanosvgrast.h>
 #include <numeric>
 #include <vector>
 #include <string>
@@ -926,7 +926,7 @@ void Plater::priv::init()
 
         auto open_external_login = [this](wxCommandEvent& evt){
              DownloaderUtils::Worker::perform_url_register();
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
             // Remove all desktop files registering prusaslicer:// url done by previous versions.
             DesktopIntegrationDialog::undo_downloader_registration_rigid();
 #if defined(SLIC3R_DESKTOP_INTEGRATION)
@@ -1276,7 +1276,7 @@ std::vector<size_t> Plater::priv::load_files(const std
     // when loading a project file. However, creating the dialog on heap causes issues on macOS, where it does not
     // appear at all. Therefore, we create the dialog on stack on Win and macOS, and on heap on Linux, which
     // is the only system that needed the workarounds in the first place.
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     auto progress_dlg = new wxProgressDialog(loading, "", 100, find_toplevel_parent(q), wxPD_APP_MODAL | wxPD_AUTO_HIDE);
     Slic3r::ScopeGuard([&progress_dlg](){ if (progress_dlg) progress_dlg->Destroy(); progress_dlg = nullptr; });
 #else
@@ -1348,7 +1348,7 @@ std::vector<size_t> Plater::priv::load_files(const std
         Slic3r::Model model;
         bool is_project_file = false;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // On Linux Constructor of the ProgressDialog calls DisableOtherWindows() function which causes a disabling of all children of the find_toplevel_parent(q)
         // And a destructor of the ProgressDialog calls ReenableOtherWindows() function which revert previously disabled children.
         // But if printer technology will be changes during project loading,
@@ -3591,7 +3591,7 @@ void Plater::priv::on_right_click(RBtnEvent& evt)
         Vec2d mouse_position = evt.data.first;
         wxPoint position(static_cast<int>(mouse_position.x()),
                          static_cast<int>(mouse_position.y()));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // For some reason on Linux the menu isn't displayed if position is
         // specified (even though the position is sane).
         position = wxDefaultPosition;
@@ -4460,7 +4460,7 @@ void Plater::load_project(const wxString& filename)
     ScopeGuard guard([](){ s_multiple_beds.set_loading_project_flag(false);});
 
     const std::vector<fs::path>& input_paths = { into_path(filename) };
-    if (! load_files(input_paths).empty()) {
+    if (! load_files((const std::vector<boost::filesystem::path>){ into_path(filename) }).empty()) {
         // At least one file was loaded.
         p->set_project_filename(filename);
         // Save the names of active presets and project specific config into ProjectDirtyStateManager.
