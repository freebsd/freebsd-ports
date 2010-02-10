--- decode.c.orig	1996-01-07 19:46:37.000000000 +0900
+++ decode.c	2010-01-28 10:48:29.000000000 +0900
@@ -265,7 +265,7 @@
     fprintf(stderr, " ) ");
     if (head->tstamp != 0) {
 	p = head->time;
-	tm.tm_year = (p[3]>>1)+80;
+	tm.tm_year = (p[3]>>1)+1980;
 	tm.tm_mon = (p[3]&0x01)<<3;
 	tm.tm_mon += (p[2]>>5) - 1;
 	tm.tm_mday = p[2]&0x1f;
