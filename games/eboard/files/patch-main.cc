--- main.cc.orig	Mon Jan 22 18:57:40 2007
+++ main.cc	Tue Jan 30 21:07:51 2007
@@ -139,7 +139,7 @@
   char devname[64];
 
   for(i=0;i<10;i++) {
-    snprintf(devname,64,"/dev/js%d",i);
+    snprintf(devname,64,"/dev/input/js%d",i);
     fd = open(devname,O_RDONLY);
     if (fd >= 0) break;
   }
