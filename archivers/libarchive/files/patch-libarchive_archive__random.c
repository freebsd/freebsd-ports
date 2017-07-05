--- libarchive/archive_random.c.orig	2017-03-20 12:41:38 UTC
+++ libarchive/archive_random.c
@@ -222,7 +222,7 @@ arc4_stir(void)
 	 * Discard early keystream, as per recommendations in:
 	 * "(Not So) Random Shuffles of RC4" by Ilya Mironov.
 	 */
-	for (i = 0; i < 1024; i++)
+	for (i = 0; i < 3072; i++)
 		(void)arc4_getbyte();
 	arc4_count = 1600000;
 }
