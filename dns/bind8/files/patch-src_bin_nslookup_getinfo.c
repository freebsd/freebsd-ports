--- src/bin/nslookup/getinfo.c.Dist	Tue May 21 21:06:57 2002
+++ src/bin/nslookup/getinfo.c	Sat May 10 14:27:57 2003
@@ -944,7 +944,7 @@
 		      p[9] & 0xf, (p[9] >> 4) & 0xf,
 		      p[8] & 0xf, (p[8] >> 4) & 0xf,
 		      p[7] & 0xf, (p[7] >> 4) & 0xf,
-		      p[6] & 0xf, (p[4] >> 4) & 0xf,
+		      p[6] & 0xf, (p[6] >> 4) & 0xf,
 		      p[5] & 0xf, (p[5] >> 4) & 0xf,
 		      p[4] & 0xf, (p[4] >> 4) & 0xf,
 		      p[3] & 0xf, (p[3] >> 4) & 0xf,
@@ -964,7 +964,7 @@
 		      p[9] & 0xf, (p[9] >> 4) & 0xf,
 		      p[8] & 0xf, (p[8] >> 4) & 0xf,
 		      p[7] & 0xf, (p[7] >> 4) & 0xf,
-		      p[6] & 0xf, (p[4] >> 4) & 0xf,
+		      p[6] & 0xf, (p[6] >> 4) & 0xf,
 		      p[5] & 0xf, (p[5] >> 4) & 0xf,
 		      p[4] & 0xf, (p[4] >> 4) & 0xf,
 		      p[3] & 0xf, (p[3] >> 4) & 0xf,
