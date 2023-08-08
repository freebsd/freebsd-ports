--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2023-07-25 09:25:50 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_
 
@@ -42,4 +42,4 @@ class DesktopIntegrationDialog : public wxDialog (priv
 } // namespace Slic3r
 
 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
\ No newline at end of file
+#endif // __linux__
