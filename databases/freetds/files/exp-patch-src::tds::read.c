--- src/tds/read.c.orig	Thu Jan 15 17:04:28 2004
+++ src/tds/read.c	Thu Jan 15 17:04:35 2004
@@ -164,6 +164,13 @@
 			buflen -= len;
 			got += len;
 		} 
+
+		/* When we get a timeout on select(), return 0. Don't return -1, because
+		 * that would lead to a disconnect
+		 * OTOH, do not let this pass to prevent an infinite loop when there is
+		 * no data on the wire */
+		if (retcode == 0)
+			return 0;
 		
 		OK_TIMEOUT:
 		now = time(NULL);
