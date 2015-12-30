--- src/3rdparty/3rdparty.pro.orig	2015-11-24 15:13:30.000000000 +0100
+++ src/3rdparty/3rdparty.pro	2015-12-23 10:01:28.113511000 +0100
@@ -2,12 +2,10 @@
 TEMPLATE = subdirs
 SUBDIRS = \
     spatialindexnavel \
-    stemmer \
-    quazip
+    stemmer
+
+# FreeBSD: prefer quazip and opennurbs from dependent ports
 
-!r_no_opennurbs {
-    SUBDIRS += opennurbs
-}
 !rs_no_dxf {
     SUBDIRS += dxflib
 }
