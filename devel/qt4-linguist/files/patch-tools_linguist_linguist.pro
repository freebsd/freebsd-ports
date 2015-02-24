--- tools/linguist/linguist.pro.orig	2015-02-23 21:20:45 UTC
+++ tools/linguist/linguist.pro
@@ -1,6 +1,2 @@
 TEMPLATE = subdirs
-SUBDIRS  = \
-    lrelease \
-    lupdate \
-    lconvert
-!no-png:!contains(QT_CONFIG, no-gui):SUBDIRS += linguist
+SUBDIRS  = linguist
