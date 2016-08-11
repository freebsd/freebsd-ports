author:  Andriy Gapon

--- src/examples/tty-continuous.c.orig	2001-12-13 21:11:15 UTC
+++ src/examples/tty-continuous.c
@@ -175,7 +175,6 @@ static void utterance_loop()
 	 * listening until current utterance completely decoded
 	 */
 	ad_stop_rec (ad);
-	while (ad_read (ad, adbuf, 4096) >= 0);
 	cont_ad_reset (cont);
 
 	printf ("Stopped listening, please wait...\n"); fflush (stdout);
