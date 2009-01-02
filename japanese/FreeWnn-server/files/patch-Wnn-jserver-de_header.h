Index: Wnn/jserver/de_header.h
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/jserver/de_header.h,v
retrieving revision 1.1
diff -d -u -I\$FreeBSD: /tmp/pcvs/ports/japanese/FreeWnn-server/files/patch-Wnn-jserver-de_header.h,v 1.2 2009-01-02 11:49:47 hrs Exp $ -I\$NetBSD:.*\$ -I\$OpenBSD:.*\$ -I\$DragonFly:.*\$ -I\$Id:.*\$ -I\$Translation:.*\$ -I\$hrs:.*\$ -w -r1.1 de_header.h
--- Wnn/jserver/de_header.h	20 Dec 2008 07:13:30 -0000	1.1
+++ Wnn/jserver/de_header.h	2 Jan 2009 10:20:44 -0000
@@ -52,6 +52,8 @@
 #  endif        /* KOREAN */
 #endif        /* CHINESE */
 
+#include <netdb.h>
+
 #include "jslib.h"
 #include "commonhd.h"
 #include "jdata.h"
@@ -205,6 +207,10 @@
 
 GLOBAL char jserver_dir[MAXPATHLEN];
 GLOBAL char jserverrcfile[MAXPATHLEN];
+
+#define MAXLISTENADDR	256
+GLOBAL char listenaddr[MAXLISTENADDR][NI_MAXHOST];
+
 GLOBAL char *hinsi_file_name GLOBAL_VAL(NULL);
 GLOBAL char lang_dir[MAXPATHLEN];
 
