- Enable IPv6 support for VNC per default to be able to set
the VRDE properties VNCPort4 and VNCPort6.

Submitted by:	Stefan Bethke <stb@lassitu.de>
--- src/VBox/ExtPacks/VNC/VBoxVNC.cpp.orig	2013-04-12 12:37:47.000000000 +0200
+++ src/VBox/ExtPacks/VNC/VBoxVNC.cpp	2013-05-02 23:57:13.543217587 +0200
@@ -44,7 +44,7 @@
 
 #ifdef LIBVNCSERVER_IPv6
 // enable manually!
-// #define VBOX_USE_IPV6
+ #define VBOX_USE_IPV6
 #endif
 
 
