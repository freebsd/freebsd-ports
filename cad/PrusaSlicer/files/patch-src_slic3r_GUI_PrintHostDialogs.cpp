--- src/slic3r/GUI/PrintHostDialogs.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/PrintHostDialogs.cpp
@@ -105,8 +105,8 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
     if (size_t extension_start = recent_path.find_last_of('.'); extension_start != std::string::npos)
         m_valid_suffix = recent_path.substr(extension_start);
     // .gcode suffix control
-    auto validate_path = [this](const wxString &path) -> bool {
-        if (!path.Lower().EndsWith(m_valid_suffix.Lower())) {
+    auto validate_path = [this](const std::wstring &path) -> bool {
+        if (! (new wxString(path))->Lower().EndsWith(m_valid_suffix.Lower())) {
             MessageDialog msg_wingow(this, wxString::Format(_L("Upload filename doesn't end with \"%s\". Do you wish to continue?"), m_valid_suffix), wxString(SLIC3R_APP_NAME), wxYES | wxNO);
             return msg_wingow.ShowModal() == wxID_YES;
         }
@@ -115,7 +115,7 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
 
     auto* btn_ok = add_button(wxID_OK, true, _L("Upload"));
     btn_ok->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-        if (validate_path(txt_filename->GetValue())) {
+        if (validate_path(txt_filename->GetValue().ToStdWstring())) {
             post_upload_action = PrintHostPostUploadAction::None;
             EndDialog(wxID_OK);
         }
@@ -125,7 +125,7 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
     if (post_actions.has(PrintHostPostUploadAction::QueuePrint)) {
         auto* btn_print = add_button(wxID_ADD, false, _L("Upload to Queue"));
         btn_print->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::QueuePrint;
                 EndDialog(wxID_OK);
             }
@@ -135,7 +135,7 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
     if (post_actions.has(PrintHostPostUploadAction::StartPrint)) {
         auto* btn_print = add_button(wxID_YES, false, _L("Upload and Print"));
         btn_print->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::StartPrint;
                 EndDialog(wxID_OK);
             }
@@ -146,7 +146,7 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
         // Using wxID_MORE as a button identifier to be different from the other buttons, wxID_MORE has no other meaning here.
         auto* btn_simulate = add_button(wxID_MORE, false, _L("Upload and Simulate"));
         btn_simulate->Bind(wxEVT_BUTTON, [this, validate_path](wxCommandEvent&) {
-            if (validate_path(txt_filename->GetValue())) {
+            if (validate_path(txt_filename->GetValue().ToStdWstring())) {
                 post_upload_action = PrintHostPostUploadAction::StartSimulation;
                 EndDialog(wxID_OK);
             }        
@@ -156,7 +156,7 @@ PrintHostSendDialog::PrintHostSendDialog(const fs::pat
     add_button(wxID_CANCEL);
     finalize();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // On Linux with GTK2 when text control lose the focus then selection (colored background) disappears but text color stay white
     // and as a result the text is invisible with light mode
     // see https://github.com/prusa3d/PrusaSlicer/issues/4532
