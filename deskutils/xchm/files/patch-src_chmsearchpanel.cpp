--- src/chmsearchpanel.cpp.orig	2026-09-16 10:59:55 UTC
+++ src/chmsearchpanel.cpp
@@ -30,6 +30,17 @@
 #include <wx/utils.h>
 #include <wx/wx.h>
 
+namespace std {
+    template<>
+    struct hash<wxString> {
+        size_t operator()(const wxString& s) const noexcept {
+            // Konvertiert den wxString intern in einen std::wstring,
+            // welcher bereits einen integrierten std::hash besitzt.
+            return std::hash<std::wstring>{}(s.ToStdWstring());
+        }
+    };
+}
+
 CHMSearchPanel::CHMSearchPanel(wxWindow* parent, wxTreeCtrl* topics, CHMHtmlNotebook* nbhtml)
     : wxPanel(parent), _tcl(topics)
 {
