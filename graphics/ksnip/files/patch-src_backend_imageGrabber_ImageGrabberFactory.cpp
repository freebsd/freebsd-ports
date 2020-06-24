--- src/backend/imageGrabber/ImageGrabberFactory.cpp.orig	2020-06-24 10:56:45 UTC
+++ src/backend/imageGrabber/ImageGrabberFactory.cpp
@@ -25,7 +25,7 @@ AbstractImageGrabber* ImageGrabberFactory::createImage
     return new MacImageGrabber();
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
     if (PlatformChecker::instance()->isX11()) {
         return new X11ImageGrabber();
     } else if (PlatformChecker::instance()->isWayland() && PlatformChecker::instance()->isKde()) {
