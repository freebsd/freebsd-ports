--- src/slic3r/GUI/EditGCodeDialog.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/EditGCodeDialog.hpp
@@ -117,7 +117,7 @@ class ParamsNode (public)
 
 public:
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxIcon      icon;
 #else
     wxBitmap    icon;
