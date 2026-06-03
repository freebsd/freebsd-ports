--- src/slic3r/GUI/PrintHostDialogs.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/PrintHostDialogs.cpp
@@ -180,7 +180,7 @@ void PrintHostSendDialog::init()
     add_button(wxID_CANCEL,false, L("Cancel"));
     finalize();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // On Linux with GTK2 when text control lose the focus then selection (colored background) disappears but text color stay white
     // and as a result the text is invisible with light mode
     // see https://github.com/prusa3d/PrusaSlicer/issues/4532
@@ -891,7 +891,7 @@ void ElegooPrintHostSendDialog::init() {
     add_button(wxID_CANCEL, false, _L("Cancel"));
     finalize();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // On Linux with GTK2 when text control lose the focus then selection (colored background) disappears but text color stay white
     // and as a result the text is invisible with light mode
     // see https://github.com/prusa3d/PrusaSlicer/issues/4532
