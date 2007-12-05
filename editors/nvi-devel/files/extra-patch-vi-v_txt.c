--- ../vi/v_txt.c.orig	2001-07-26 13:15:53.000000000 -0400
+++ ../vi/v_txt.c	2007-11-15 13:57:33.000000000 -0500
@@ -589,7 +589,7 @@
 
 	/* Check to see if the character fits into the replay buffers. */
 	if (LF_ISSET(TXT_RECORD)) {
-		BINC_GOTO(sp, (char *)vip->rep,
+		BINC_GOTO(sp, vip->rep,
 		    vip->rep_len, (rcol + 1) * sizeof(EVENT));
 		vip->rep[rcol++] = *evp;
 	}
