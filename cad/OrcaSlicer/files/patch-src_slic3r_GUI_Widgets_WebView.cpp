--- src/slic3r/GUI/Widgets/WebView.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Widgets/WebView.cpp
@@ -20,7 +20,7 @@
 #include <WebView2.h>
 #include <Shellapi.h>
 #include <slic3r/Utils/Http.hpp>
-#elif defined __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <gtk/gtk.h>
 #define WEBKIT_API
 struct WebKitWebView;
@@ -275,9 +275,13 @@ wxWebView* WebView::CreateWebView(wxWindow * parent, w
         webView->RegisterHandler(wxSharedPtr<wxWebViewHandler>(new wxWebViewFSHandler("memory")));
 #else
         // With WKWebView handlers need to be registered before creation
-        webView->RegisterHandler(wxSharedPtr<wxWebViewHandler>(new wxWebViewArchiveHandler("wxfs")));
-        // And the memory: file system
-        webView->RegisterHandler(wxSharedPtr<wxWebViewHandler>(new wxWebViewFSHandler("memory")));
+        static bool handlers_registered = false;
+        if (!handlers_registered) {
+            webView->RegisterHandler(wxSharedPtr<wxWebViewHandler>(new wxWebViewArchiveHandler("wxfs")));
+            // And the memory: file system
+            webView->RegisterHandler(wxSharedPtr<wxWebViewHandler>(new wxWebViewFSHandler("memory")));
+            handlers_registered = true;
+        }
         webView->Create(parent, wxID_ANY, url2, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
         webView->SetUserAgent(wxString::Format("BBL-Slicer/v%s (%s) Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko)", SLIC3R_VERSION,
                                                Slic3r::GUI::wxGetApp().dark_mode() ? "dark" : "light"));
