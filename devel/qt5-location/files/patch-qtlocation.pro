Do not look for Geoclue, it brings some additional glib-related dependencies
that are not worth it, given that in Qt 5.6 it is no longer a dependency.

--- qtlocation.pro.orig	2016-01-20 16:52:51 UTC
+++ qtlocation.pro
@@ -1,6 +1,4 @@
 load(configure)
-qtCompileTest(geoclue)
-qtCompileTest(geoclue-satellite)
 qtCompileTest(gypsy)
 
 load(qt_parts)
