--- src/slic3r/GUI/DesktopIntegrationDialog.hpp.orig	2025-03-07 08:28:42 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.hpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #ifndef slic3r_DesktopIntegrationDialog_hpp_
 #define slic3r_DesktopIntegrationDialog_hpp_

@@ -39,4 +39,4 @@
 } // namespace Slic3r

 #endif // slic3r_DesktopIntegrationDialog_hpp_
-#endif // __linux__
+#endif // __linux__ || __FreeBSD__
