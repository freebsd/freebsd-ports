--- db.c.orig	2005-06-20 02:53:38 UTC
+++ db.c
@@ -551,11 +551,11 @@ encode_data(size_t len, char *data, char
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
