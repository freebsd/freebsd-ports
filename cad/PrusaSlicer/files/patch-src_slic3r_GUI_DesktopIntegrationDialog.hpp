--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -2,7 +2,7 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -49,4 +49,4 @@ class DesktopIntegrationDialog : public wxDialog (publ
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
