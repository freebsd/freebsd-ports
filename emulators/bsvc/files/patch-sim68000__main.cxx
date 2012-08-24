--- ./sim68000/main.cxx.orig	2012-08-24 12:25:03.072914000 +0200
+++ ./sim68000/main.cxx	2012-08-24 12:37:47.584914549 +0200
@@ -19,6 +19,7 @@
 #include "devices/DeviceRegistry.hxx"
 #include "loader/Loader.hxx"
 
+int
 main()
 {
   BasicCPU& processor = *(new m68000);
