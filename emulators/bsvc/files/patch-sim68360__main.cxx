--- ./sim68360/main.cxx.orig	2012-08-24 12:25:01.322915000 +0200
+++ ./sim68360/main.cxx	2012-08-24 12:40:04.506914092 +0200
@@ -22,6 +22,7 @@
 #include "devices/DeviceRegistry.hxx"
 #include "loader/Loader.hxx"
 
+int
 main()
 {
   BasicCPU& processor = *(new cpu32);
