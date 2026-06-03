--- src/slic3r/GUI/Widgets/WebView.cpp.orig	2026-03-22 17:56:38 UTC
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
