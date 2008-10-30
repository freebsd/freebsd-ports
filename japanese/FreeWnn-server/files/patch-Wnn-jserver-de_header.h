--- Wnn/jserver/de_header.h.orig	2004-12-30 02:45:32.000000000 +0900
+++ Wnn/jserver/de_header.h	2008-10-30 15:45:17.000000000 +0900
@@ -52,6 +52,8 @@
 #  endif        /* KOREAN */
 #endif        /* CHINESE */
 
+#include <netdb.h>
+
 #include "jslib.h"
 #include "commonhd.h"
 #include "jdata.h"
@@ -205,6 +207,7 @@
 
 GLOBAL char jserver_dir[MAXPATHLEN];
 GLOBAL char jserverrcfile[MAXPATHLEN];
+GLOBAL char listenaddr[NI_MAXHOST];
 GLOBAL char *hinsi_file_name GLOBAL_VAL(NULL);
 GLOBAL char lang_dir[MAXPATHLEN];
 
