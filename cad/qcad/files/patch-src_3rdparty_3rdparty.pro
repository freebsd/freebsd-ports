--- ./src/3rdparty/3rdparty.pro.orig	2013-08-06 17:32:09.000000000 +0200
+++ ./src/3rdparty/3rdparty.pro	2013-08-08 10:03:33.000000000 +0200
@@ -4,9 +4,8 @@
     spatialindexnavel \
     stemmer
 
-!r_no_opennurbs {
-    SUBDIRS += opennurbs
-}
+# FreeBSD: prefer opennurbs from a dependent port
+
 !rs_no_dxf {
     SUBDIRS += dxflib
 }
