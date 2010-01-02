Index: Wnn/jserver/de_header.h
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/de_header.h,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- Wnn/jserver/de_header.h	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/jserver/de_header.h	2 Jan 2009 11:46:51 -0000	1.3
@@ -52,6 +52,8 @@
 #  endif        /* KOREAN */
 #endif        /* CHINESE */
 
+#include <netdb.h>
+
 #include "jslib.h"
 #include "commonhd.h"
 #include "jdata.h"
@@ -205,6 +207,10 @@ GLOBAL int option_flag GLOBAL_VAL(0);
 
 GLOBAL char jserver_dir[MAXPATHLEN];
 GLOBAL char jserverrcfile[MAXPATHLEN];
+
+#define MAXLISTENADDR	256
+GLOBAL char listenaddr[MAXLISTENADDR][NI_MAXHOST];
+
 GLOBAL char *hinsi_file_name GLOBAL_VAL(NULL);
 GLOBAL char lang_dir[MAXPATHLEN];
 
