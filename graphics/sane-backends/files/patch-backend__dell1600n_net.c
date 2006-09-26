--- backend/dell1600n_net.c.orig	Tue Jun 20 06:07:52 2006
+++ backend/dell1600n_net.c	Fri Sep 15 01:42:26 2006
@@ -73,6 +73,8 @@
 #include <netinet/in.h>
 #include <netdb.h>
 
+#include <sys/time.h>
+
 #include <jpeglib.h>
 #include <tiffio.h>
 
@@ -1762,7 +1764,7 @@
 ProcessPageData (struct ScannerState *pState)
 {
 
-  char tempFilename[TMP_MAX] = "scan.dat";
+  char tempFilename[L_tmpnam] = "scan.dat";
   FILE *fTmp;
   int fdTmp;
   struct jpeg_source_mgr jpegSrcMgr;
