--- src/slic3r/GUI/TopBar.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/TopBar.cpp
@@ -52,7 +52,7 @@ TopBarItemsCtrl::Button::Button(wxWindow* parent, cons
     Bind(wxEVT_LEAVE_WINDOW, [this](wxMouseEvent& event) { set_hovered(false); event.Skip(); });
 
     Bind(wxEVT_PAINT,        [this](wxPaintEvent&) { render(); });
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     Bind(wxEVT_LEFT_UP,      [this](wxMouseEvent& event) {
 #else
     Bind(wxEVT_LEFT_DOWN,    [this](wxMouseEvent& event) {
