--- src/slic3r/GUI/ConfigWizard.cpp.orig	2025-03-07 08:28:42 UTC
+++ src/slic3r/GUI/ConfigWizard.cpp
@@ -50,11 +50,11 @@
 #include "UnsavedChangesDialog.hpp"
 #include "MainFrame.hpp"

-#if defined(__linux__) && defined(__WXGTK3__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__WXGTK3__)
 #define wxLinux_gtk3 true
 #else
 #define wxLinux_gtk3 false
-#endif //defined(__linux__) && defined(__WXGTK3__)
+#endif //(defined(__linux__) || defined(__FreeBSD__)) && defined(__WXGTK3__)

 namespace Slic3r {

@@ -532,7 +532,7 @@
     const bool data_empty = run_reason == ConfigWizard::RR_DATA_EMPTY;
     welcome_text->Show(data_empty);
     cbox_reset->Show(!data_empty);
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     if (!DesktopIntegrationDialog::is_integrated())
         cbox_integrate->Show(true);
     else
