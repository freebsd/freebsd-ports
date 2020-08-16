--- include/LibreOfficeKit/LibreOfficeKitInit.h.orig	2016-10-28 14:50:26 UTC
+++ include/LibreOfficeKit/LibreOfficeKitInit.h
@@ -19,7 +19,7 @@ extern "C"
 
 #if defined(__linux__) || defined (__FreeBSD_kernel__) || defined(_AIX) ||\
     defined(_WIN32) || defined(__APPLE__) || defined (__NetBSD__) ||\
-    defined (__sun) || defined(__OpenBSD__)
+    defined (__sun) || defined(__OpenBSD__) || defined (__FreeBSD__)
 
 #include <stdio.h>
 #include <stdlib.h>
