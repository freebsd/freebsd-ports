Second hunk: fix a version of the shipped qtscriptgenerator, as when updating Qt, the new one might
not yet be bundled in the tarball.

--- src/3rdparty/3rdparty.pro.orig	2026-05-06 14:27:07 UTC
+++ src/3rdparty/3rdparty.pro
@@ -19,7 +19,7 @@ else {
     }
     else {
         # Qt 6: use newer opennurbs library
-        SUBDIRS += opennurbs
+        # FreeBSD: prefer opennurbs from dependent ports
     }
 }
 !rs_no_dxf {
