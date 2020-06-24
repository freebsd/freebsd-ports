--- src/backend/imageGrabber/ImageGrabberFactory.h.orig	2020-06-24 10:32:45 UTC
+++ src/backend/imageGrabber/ImageGrabberFactory.h
@@ -24,7 +24,7 @@
 #include "MacImageGrabber.h"
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "X11ImageGrabber.h"
 #include "KdeWaylandImageGrabber.h"
 #include "GnomeWaylandImageGrabber.h"
