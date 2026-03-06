--- src/slic3r/GUI/DesktopIntegrationDialog.cpp.orig	2025-03-07 08:28:42 UTC
+++ src/slic3r/GUI/DesktopIntegrationDialog.cpp
@@ -1,4 +1,4 @@
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #include "GUI_App.hpp"
 #include "GUI.hpp"
@@ -667,4 +667,4 @@

 } // namespace GUI
 } // namespace Slic3r
-#endif // __linux__
+#endif // __linux__ || __FreeBSD__
