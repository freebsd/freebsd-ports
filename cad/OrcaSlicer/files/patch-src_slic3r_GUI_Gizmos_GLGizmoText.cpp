--- src/slic3r/GUI/Gizmos/GLGizmoText.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Gizmos/GLGizmoText.cpp
@@ -91,7 +91,7 @@ bool can_load(const wxFont &font)
     return hfont != nullptr;
 #elif defined(__APPLE__)
     return true;
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     return true;
 #endif
     return false;
