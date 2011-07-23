--- ./zmtx.c.orig	1996-12-11 23:24:08.000000000 -0800
+++ ./zmtx.c	2011-07-22 17:33:19.613253798 -0700
@@ -15,6 +15,7 @@
 
 #include <ctype.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <string.h>
@@ -65,7 +66,7 @@
 
 	cps = ftell(fp) / duration;
 
-	fprintf(stderr,"zmtx: sending file \"%s\" %8ld bytes (%3d %%/%5d cps)           \r",
+	fprintf(stderr,"sending file \"%s\" %8ld bytes (%3d %%/%5d cps)\r",
 		name,ftell(fp),percentage,cps);
 }
 
@@ -201,7 +202,7 @@
 		if (opt_v) {
 			fprintf(stderr,"zmtx: can't open file %s\n",name);
 		}
-		return;
+		return FALSE;
 	}
 
 	fstat(fileno(fp),&s);
@@ -357,7 +358,7 @@
 			if (opt_v) {
 				fprintf(stderr,"zmtx: skipped file \"%s\"                       \n",name);
 			}
-			return;
+			return FALSE;
 		}
 
 	} while (type != ZRPOS);
