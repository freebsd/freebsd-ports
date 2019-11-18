Disable not yet functional Qt quick based map viewer

See https://github.com/bjorn/tiled/issues/2673
--- src/src.pro.orig	2019-11-13 09:21:48 UTC
+++ src/src.pro
@@ -13,6 +13,5 @@ SUBDIRS = \
 
 minQtVersion(5, 4, 0) {
     SUBDIRS += \
-        tiledquickplugin \
-        tiledquick
+        tiledquickplugin
 }
