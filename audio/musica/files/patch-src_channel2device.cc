--- src/channel2device.cc.orig	2007-12-18 19:44:10.000000000 +0100
+++ src/channel2device.cc	2007-12-18 19:44:31.000000000 +0100
@@ -45,7 +45,7 @@
 
 
 
-static char *deviceType = "channel-to-device";
+static char deviceType[] = "channel-to-device";
 
 
 
