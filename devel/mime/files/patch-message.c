--- message.c.orig	Tue Aug 31 10:14:24 2010
+++ message.c	Tue Aug 31 10:14:10 2010
@@ -89,7 +89,7 @@
 		 * XXX - need to be fixed to support "\r\n"
 		 */
 		bdcm = bd_makenorm(bd, crlfpair);
-		bdlc = memmem(pos, len - (pos - msg), bdcm, strlen(bdcm));
+		bdlc = memmemory(pos, len - (pos - msg), bdcm, strlen(bdcm));
 		free(bdcm);
 
 		if (bdlc != pos) {
@@ -144,10 +144,10 @@
 	len -= strlen(strstr(bdnorm, "--"));
 
 	for (;;) {
-		ret = realloc(ret, sizeof *ret * *cnt + 1);
+		ret = realloc(ret, sizeof(*ret) * (*cnt + 1));
 
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
 
