--- modules/archive/zip/header.c.orig	2003-01-01 06:22:34 UTC
+++ modules/archive/zip/header.c
@@ -25,7 +25,7 @@
 #include "zip.h"
 
 
-ZipStatus
+CxStatus
 cxZipReadLocalHeader(ZipLocalHeader *header, CxFP *fp)
 {
 	char buffer[ZIP_LOCAL_HEADER_SIZE];
