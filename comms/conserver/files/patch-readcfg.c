--- etc/conserver/readcfg.c.orig	Wed Aug  2 19:39:42 2000
+++ etc/conserver/readcfg.c	Tue Jul 24 12:09:27 2001
@@ -194,7 +194,7 @@
 			if ('\000' != pGE->passwd[0] && 0 != strcmp(pcPass, pGE->passwd)) {
 				fprintf(stderr, "%s: %s(%d) group %d has more than one password, first taken\n", progname, pcFile, iLine, iG);
 			} else if ((int)strlen(pcPass) > MAXPSWDLEN) {
-				fprintf(stderr, "%s: %s(%d) password too long (%d is the limit)\n", progname, pcFile, iLine, iG, MAXPSWDLEN);
+				fprintf(stderr, "%s: %s(%d) password too long (%d is the limit)\n", progname, pcFile, iLine, MAXPSWDLEN);
 			} else {
 				(void)strcpy(pGE->passwd, pcPass);
 			}

