--- ./zmrx.c.orig	1996-12-11 23:24:08.000000000 -0800
+++ ./zmrx.c	2011-07-22 17:33:19.603250928 -0700
@@ -15,6 +15,7 @@
 
 #include <ctype.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <string.h>
@@ -70,7 +71,7 @@
 
 	cps = ftell(fp) / duration;
 
-	fprintf(stderr,"zmrx: receiving file \"%s\" %8ld bytes (%3d %%/%5d cps)           \r",
+	fprintf(stderr,"receiving file \"%s\" %8ld bytes (%3d %%/%5d cps)\r",
 		name,ftell(fp),percentage,cps);
 }
 
@@ -223,7 +224,7 @@
 	}
 
 	if (opt_v) {
-		fprintf(stderr,"zmrx: receiving file \"%s\"\r",name);
+		fprintf(stderr,"receiving file \"%s\"\r",name);
 	}
 
 	sscanf(rx_data_subpacket + strlen(rx_data_subpacket) + 1,
@@ -342,7 +343,7 @@
 	 */
 
 	if (opt_v) {
-		fprintf(stderr,"zmrx: received file \"%s\"                 \n",name);
+		fprintf(stderr,"zmrx: received file \"%s\"\n",name);
 	}
 }
 
