--- doomsday/libgui/src/displaymode_x11.cpp.orig	2016-02-01 03:37:12 UTC
+++ doomsday/libgui/src/displaymode_x11.cpp
@@ -54,8 +54,12 @@ public:
     /**
      * Queries all the available modes in the display configuration.
      */
-    RRInfo() : _numSizes(0)
+    RRInfo() : _conf(NULL), _numSizes(0)
     {
+        int dummy;
+        if (!XRRQueryExtension(QX11Info::display(), &dummy, &dummy))
+            return; // Not available.
+
         _conf = XRRGetScreenInfo(QX11Info::display(), QX11Info::appRootWindow());
         if(!_conf) return; // Not available.
 
