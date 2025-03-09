Second hunk: fix a version of the shipped qtscriptgenerator, as when updating Qt, the new one might
not yet be bundled in the tarball.

--- src/3rdparty/3rdparty.pro.orig	2025-02-10 09:29:49 UTC
+++ src/3rdparty/3rdparty.pro
@@ -11,9 +11,8 @@ else {
     SUBDIRS += legacy
 }
 
-!r_no_opennurbs {
-    SUBDIRS += opennurbs
-}
+# FreeBSD: prefer opennurbs from dependent ports
+
 !rs_no_dxf {
     SUBDIRS += dxflib
 }
