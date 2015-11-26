Make external libraries part of the default build. They are currently built
before the rest, as qmake will recurse into each subdirectory in order.
--- meshlab_full.pro.bak	2015-11-21 16:25:23.812658000 +0100
+++ meshlab_full.pro	2015-11-21 16:25:32.892417000 +0100
@@ -1,7 +1,7 @@
 #config += debug_and_release
 TEMPLATE      = subdirs
 CONFIG += ordered
-SUBDIRS       = common \
+SUBDIRS       = external common \
                 meshlab \
                 meshlabserver \
 # IO plugins
