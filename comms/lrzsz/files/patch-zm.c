--- src/zm.c.orig	1998-12-29 16:48:38 UTC
+++ src/zm.c
@@ -431,10 +431,12 @@ zsdata(const char *buf, size_t length, int frameend)
 	VPRINTF(3,("zsdata: %lu %s", (unsigned long) length, 
 		Zendnames[(frameend-ZCRCE)&3]));
 	crc = 0;
-	do {
-		zsendline(*buf); crc = updcrc((0377 & *buf), crc);
-		buf++;
-	} while (--length>0);
+
+	for( ; length; length--) {
+	  zsendline(*buf); crc = updcrc((0377 & *buf), crc);
+	  buf++;
+	}
+
 	xsendline(ZDLE); xsendline(frameend);
 	crc = updcrc(frameend, crc);
 
