--- modules/archive/zip/header.c.orig	Sun Aug 15 18:08:32 2004
+++ modules/archive/zip/header.c	Sun Aug 15 18:08:34 2004
@@ -25,7 +25,7 @@
 #include "zip.h"
 
 
-ZipStatus
+CxStatus
 cxZipReadLocalHeader(ZipLocalHeader *header, CxFP *fp)
 {
 	char buffer[ZIP_LOCAL_HEADER_SIZE];
