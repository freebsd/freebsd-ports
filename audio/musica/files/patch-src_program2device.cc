--- src/program2device.cc.orig	2007-12-18 19:56:19.000000000 +0100
+++ src/program2device.cc	2007-12-18 19:56:34.000000000 +0100
@@ -45,7 +45,7 @@
 
 
 
-static char *deviceType = "program-to-device";
+static char deviceType[] = "program-to-device";
 
 
 
