--- src/xstring.c.orig	2008-03-27 17:58:25.000000000 +0100
+++ src/xstring.c	2008-03-27 18:02:39.000000000 +0100
@@ -351,10 +351,16 @@
 	uchar *dstp = dst;
 
 	while (*src) {
-		if (IsKanjiStr(src))
-			*((ushort*)dstp)++ = *((ushort*)src)++;
-		else
-			*dstp++ = (*func)(*src++);
+		if (IsKanjiStr(src)) {
+			*((ushort*)dstp) = *((ushort*)src);
+			(ushort*)src++;
+			(ushort*)dstp++;
+		}
+		else {
+			*dstp = (*func)(*src);
+			src++;
+			dstp++;
+		}
 	}
 	*dstp = 0;
 	return dstp - dst;
