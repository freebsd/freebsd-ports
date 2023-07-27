--- src/slic3r/GUI/UpdateDialogs.cpp.orig	2023-07-25 12:59:11 UTC
+++ src/slic3r/GUI/UpdateDialogs.cpp
@@ -142,7 +142,7 @@ AppUpdateDownloadDialog::AppUpdateDownloadDialog( cons
 	versions->Add(new wxStaticText(this, wxID_ANY, ver_online.to_string()));
 	content_sizer->Add(versions);
 	content_sizer->AddSpacer(VERT_SPACING);
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 	cbox_run = new wxCheckBox(this, wxID_ANY, _(L("Run installer after download. (Otherwise file explorer will be opened)")));
 	content_sizer->Add(cbox_run);
 #endif
@@ -248,7 +248,7 @@ bool AppUpdateDownloadDialog::run_after_download() con
 
 bool AppUpdateDownloadDialog::run_after_download() const
 {
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 	return cbox_run->GetValue();
 #endif
 	return false;
