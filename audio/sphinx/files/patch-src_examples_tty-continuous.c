$FreeBSD$

author:  Andriy Gapon

--- src/examples/tty-continuous.c.orig	Thu Dec 13 21:11:15 2001
+++ src/examples/tty-continuous.c	Mon Oct 20 12:12:58 2003
@@ -175,7 +175,6 @@ static void utterance_loop()
 	 * listening until current utterance completely decoded
 	 */
 	ad_stop_rec (ad);
-	while (ad_read (ad, adbuf, 4096) >= 0);
 	cont_ad_reset (cont);
 
 	printf ("Stopped listening, please wait...\n"); fflush (stdout);
