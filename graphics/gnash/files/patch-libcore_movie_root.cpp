--- libcore/movie_root.cpp.orig	2016-07-21 12:25:09 UTC
+++ libcore/movie_root.cpp
@@ -156,7 +156,7 @@ movie_root::movie_root(VirtualClock& clo
     _hostfd(-1),
     _controlfd(-1),
     _quality(QUALITY_HIGH),
-    _alignMode(0),
+    _alignMode(0ULL),
     _allowScriptAccess(SCRIPT_ACCESS_SAME_DOMAIN),
     _showMenu(true),
     _scaleMode(SCALEMODE_SHOWALL),
