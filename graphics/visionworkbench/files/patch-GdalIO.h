--- src/vw/FileIO/GdalIO.h.orig	2012-06-29 17:25:08.000000000 +0000
+++ src/vw/FileIO/GdalIO.h	2012-06-29 17:25:15.000000000 +0000
@@ -10,8 +10,8 @@
 
 #include <vw/FileIO/ScanlineIO.h>
 
-extern "C" {
 #include <gdal_priv.h>
+extern "C" {
 #include <cpl_multiproc.h>
 }
 
