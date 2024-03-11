--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -2,7 +2,7 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -46,4 +46,4 @@ class DesktopIntegrationDialog : public wxDialog (priv
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
