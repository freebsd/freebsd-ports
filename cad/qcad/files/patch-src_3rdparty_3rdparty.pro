Second hunk: fix a version of the shipped qtscriptgenerator, as when updating Qt, the new one might
not yet be bundled in the tarball.

--- src/3rdparty/3rdparty.pro.orig	2018-07-03 13:46:04 UTC
+++ src/3rdparty/3rdparty.pro
@@ -2,21 +2,19 @@ include (../../shared.pri)
 TEMPLATE = subdirs
 SUBDIRS = \
     spatialindexnavel \
-    stemmer \
-    quazip
+    stemmer
 
-!r_no_opennurbs {
-    SUBDIRS += opennurbs
-}
+# FreeBSD: prefer quazip and opennurbs from dependent ports
+
 !rs_no_dxf {
     SUBDIRS += dxflib
 }
 
 !r_mobile {
-    exists(qt-labs-qtscriptgenerator-$${QT_VERSION}) {
-        SUBDIRS += qt-labs-qtscriptgenerator-$${QT_VERSION}
+    exists(qt-labs-qtscriptgenerator-5.11.1) {
+        SUBDIRS += qt-labs-qtscriptgenerator-5.11.1
     }
     else {
-        error("Script bindings not available for Qt version $${QT_VERSION}. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-$${QT_VERSION} or use another version of Qt.")
+        error("Script bindings not available for Qt version 5.11.1. You can add them to src/3rdparty/qt-labs-qtscriptgenerator-5.11.1 or use another version of Qt.")
     }
 }
