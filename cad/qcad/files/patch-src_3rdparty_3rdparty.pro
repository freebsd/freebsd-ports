Second hunk: fix a version of the shipped qtscriptgenerator, as when updating Qt, the new one might
not yet be bundled in the tarball.

--- src/3rdparty/3rdparty.pro.orig	2019-05-04 22:28:42 UTC
+++ src/3rdparty/3rdparty.pro
@@ -4,9 +4,8 @@ SUBDIRS = \
     spatialindexnavel \
     stemmer
 
-!r_no_opennurbs {
-    SUBDIRS += opennurbs
-}
+# FreeBSD: prefer opennurbs from dependent ports
+
 !rs_no_dxf {
     SUBDIRS += dxflib
 }
