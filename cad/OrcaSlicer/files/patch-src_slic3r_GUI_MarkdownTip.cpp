--- src/slic3r/GUI/MarkdownTip.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/MarkdownTip.cpp
@@ -245,7 +245,7 @@
         _pendingScript.clear();
         return;
     }
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxString str = "0";
 #else
     wxString str = event.GetString();
