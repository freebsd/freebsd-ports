--- holyshout.h.orig	2003-11-25 08:43:07.000000000 +0100
+++ holyshout.h	2007-11-09 01:08:52.000000000 +0100
@@ -35,6 +35,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include <netdb.h>
 #include <time.h>
@@ -47,7 +48,7 @@
 #include <netinet/in.h>
 
 #include "shout/shout.h"
-#include "liblame/lame.h"
+#include "lame/lame.h"
 
 #define PROGRAM_NAME "HOLYSHOUT"
 #define VERSION "0.2"
@@ -61,9 +62,9 @@
 #define PL_FREE 3
 
 void usage(void) ;
-int send_setram (shout_conn_t conn , char *filename) ;
+int send_setram (shout_t *conn , char *filename) ;
 void s1gnal(const int sig) ;
-int send_setram_direct (shout_conn_t conn , char *filename) ;
+int send_setram_direct (shout_t *conn , char *filename) ;
 int init_playlist(int type) ;
 
 
