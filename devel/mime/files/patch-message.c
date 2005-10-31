--- message.c.orig	Tue Sep 16 03:37:19 2003
+++ message.c	Sun Oct 30 23:38:44 2005
@@ -89,7 +89,7 @@
 		 * XXX - need to be fixed to support "\r\n"
 		 */
 		bdcm = bd_makenorm(bd, crlfpair);
-		bdlc = memmem(pos, len - (pos - msg), bdcm, strlen(bdcm));
+		bdlc = memmemory(pos, len - (pos - msg), bdcm, strlen(bdcm));
 		free(bdcm);
 
 		if (bdlc != pos) {
@@ -146,8 +146,8 @@
 	for (;;) {
 		ret = realloc(ret, sizeof *ret * *cnt + 1);
 
-		if ((next = memmem(msg, len, bdnorm, bdnormlen)) == NULL)
-			next = memmem(msg, len, bdtail, bdtaillen);
+		if ((next = memmemory(msg, len, bdnorm, bdnormlen)) == NULL)
+			next = memmemory(msg, len, bdtail, bdtaillen);
 
 		ret[(*cnt)++] = mime_readmessage(msg, next - msg, crlfpair);
 
@@ -272,6 +272,7 @@
 				eqcnt++;
 				break;
 			default:
+				break;
 			}
 		}
 
