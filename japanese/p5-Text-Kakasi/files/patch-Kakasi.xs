--- Kakasi.xs.orig	Wed Apr 11 16:58:38 2001
+++ Kakasi.xs	Sat Oct  5 20:20:42 2002
@@ -110,7 +110,7 @@
 			tmp ++;
 			cur ++;
 		}
-		free(rtmp);
+		if (*rtmp) free(rtmp);
 	} while (cur < slen);
 	if (ret != NULL) {
 		RETVAL = newSVpv(ret, rcur - 1);
