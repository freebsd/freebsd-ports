--- src/lrz.c.orig	Sun Sep 28 16:02:13 2003
+++ src/lrz.c	Sun Sep 28 16:02:34 2003
@@ -1159,9 +1159,9 @@
 
 	nameend = name + 1 + strlen(name);
 	if (*nameend) {	/* file coming from Unix or DOS system */
-		long modtime;
-		long bytes_total;
-		int mode;
+		long modtime=0;
+		long bytes_total=DEFBYTL;
+		int mode=0;
 		sscanf(nameend, "%ld%lo%o", &bytes_total, &modtime, &mode);
 		zi->modtime=modtime;
 		zi->bytes_total=bytes_total;
