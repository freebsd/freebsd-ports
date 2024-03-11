--- src/slic3r/GUI/GUI_Utils.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/GUI_Utils.cpp
@@ -53,7 +53,7 @@ void on_window_geometry(wxTopLevelWindow *tlw, std::fu
     // cf. https://groups.google.com/forum/#!topic/wx-users/c7ntMt6piRI
     // OTOH the geometry is available very soon, so we can call the callback right away
     callback();
-#elif defined __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
     tlw->Bind(wxEVT_SHOW, [=](wxShowEvent &evt) {
         // On Linux, the geometry is only available after wxEVT_SHOW + CallAfter
         // cf. https://groups.google.com/forum/?pli=1#!topic/wx-users/fERSXdpVwAI
@@ -121,7 +121,7 @@ int get_dpi_for_window(const wxWindow *window)
         if (hdc == NULL) { return DPI_DEFAULT; }
         return GetDeviceCaps(hdc, LOGPIXELSX);
     }
-#elif defined __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
     // TODO
     return DPI_DEFAULT;
 #elif defined __APPLE__
