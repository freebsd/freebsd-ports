--- db.c.orig	Thu Jun 21 11:20:05 2007
+++ db.c	Thu Jun 21 11:20:32 2007
@@ -571,11 +571,11 @@
 		buflen = elen;
 	}
 	*edata = buf;
-	if (extra_echars) {
-		return (strsvisx(buf, data, len, encflags, extra_echars));
-	} else {
+//	if (extra_echars) {
+//		return (strsvisx(buf, data, len, encflags, extra_echars));
+//	} else {
 		return (strvisx(buf, data, len, encflags));
-	}
+//	}
 }
 
 int
