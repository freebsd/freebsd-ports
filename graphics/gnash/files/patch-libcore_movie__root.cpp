$NetBSD: patch-libcore_movie__root.cpp,v 1.1 2013/02/26 11:04:25 joerg Exp $

--- libcore/movie_root.cpp.orig	2013-02-25 18:54:08.000000000 +0000
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
