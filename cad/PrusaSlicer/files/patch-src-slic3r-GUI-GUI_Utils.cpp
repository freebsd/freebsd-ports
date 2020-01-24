--- src/slic3r/GUI/GUI_Utils.cpp.orig	2019-12-10 15:09:10 UTC
+++ src/slic3r/GUI/GUI_Utils.cpp
@@ -55,7 +55,7 @@ void on_window_geometry(wxTopLevelWindow *tlw, std::fu
 #endif
 }
 
-wxDEFINE_EVENT(EVT_DPI_CHANGED, DpiChangedEvent);
+wxDEFINE_EVENT(psEVT_DPI_CHANGED, DpiChangedEvent);
 
 #ifdef _WIN32
 template<class F> typename F::FN winapi_get_function(const wchar_t *dll, const char *fn_name) {
@@ -106,7 +106,7 @@ int get_dpi_for_window(wxWindow *window)
         if (hdc == NULL) { return DPI_DEFAULT; }
         return GetDeviceCaps(hdc, LOGPIXELSX);
     }
-#elif defined __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
     // TODO
     return DPI_DEFAULT;
 #elif defined __APPLE__
