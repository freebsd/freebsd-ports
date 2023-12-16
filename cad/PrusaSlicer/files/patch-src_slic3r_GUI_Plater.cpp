--- src/slic3r/GUI/Plater.cpp.orig	2023-06-19 12:07:14 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -2452,7 +2452,7 @@ std::vector<size_t> Plater::priv::load_files(const std
     // when loading a project file. However, creating the dialog on heap causes issues on macOS, where it does not
     // appear at all. Therefore, we create the dialog on stack on Win and macOS, and on heap on Linux, which
     // is the only system that needed the workarounds in the first place.
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     auto progress_dlg = new wxProgressDialog(loading, "", 100, find_toplevel_parent(q), wxPD_APP_MODAL | wxPD_AUTO_HIDE);
     Slic3r::ScopeGuard([&progress_dlg](){ if (progress_dlg) progress_dlg->Destroy(); progress_dlg = nullptr; });
 #else
@@ -2498,7 +2498,7 @@ std::vector<size_t> Plater::priv::load_files(const std
         bool is_project_file = type_prusa;
         try {
             if (type_3mf || type_zip_amf) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                 // On Linux Constructor of the ProgressDialog calls DisableOtherWindows() function which causes a disabling of all children of the find_toplevel_parent(q)
                 // And a destructor of the ProgressDialog calls ReenableOtherWindows() function which revert previously disabled children.
                 // But if printer technology will be changes during project loading, 
@@ -4428,7 +4428,7 @@ void Plater::priv::on_right_click(RBtnEvent& evt)
         Vec2d mouse_position = evt.data.first;
         wxPoint position(static_cast<int>(mouse_position.x()),
                          static_cast<int>(mouse_position.y()));
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         // For some reason on Linux the menu isn't displayed if position is
         // specified (even though the position is sane).
         position = wxDefaultPosition;
@@ -5281,7 +5281,7 @@ void Plater::load_project(const wxString& filename)
 
     p->reset();
 
-    if (! load_files({ into_path(filename) }).empty()) {
+    if (! load_files((const std::vector<boost::filesystem::path>){ into_path(filename) }).empty()) {
         // At least one file was loaded.
         p->set_project_filename(filename);
         // Save the names of active presets and project specific config into ProjectDirtyStateManager.
