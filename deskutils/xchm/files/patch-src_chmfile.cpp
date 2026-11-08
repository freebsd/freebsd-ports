--- src/chmfile.cpp.orig	2026-09-16 10:59:55 UTC
+++ src/chmfile.cpp
@@ -33,6 +33,17 @@
 #include <wx/wx.h>
 #include <wxstringutils.h>
 
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
 namespace {
 
 //! Maximum allowed number of search-returned items.
