--- src/itdb_itunesdb.c.orig	Tue Oct 18 22:31:11 2005
+++ src/itdb_itunesdb.c	Tue Oct 18 22:32:56 2005
@@ -477,9 +477,11 @@
  * return value after use */
 static struct playcount *playcount_get_next (FImport *fimp)
 {
+    struct playcount *playcount;
+
     g_return_val_if_fail (fimp, NULL);
 
-    struct playcount *playcount = g_list_nth_data (fimp->playcounts, 0);
+    playcount = g_list_nth_data (fimp->playcounts, 0);
 
     if (playcount)
 	fimp->playcounts = g_list_remove (fimp->playcounts, playcount);
@@ -1779,9 +1781,10 @@
 	if (cmp_n_bytes_seek (cts, "mhsd", seek, 4))
 	{   /* We just check if it's actually a playlist mhsd (type=2)
 	       or not (type = 1, should not be...) */
+	    guint32 type;
 	    guint32 len = get32lint (cts, seek+8);
 	    CHECK_ERROR (fimp, FALSE);
-	    guint32 type = get32lint (cts, seek+12);
+	    type = get32lint (cts, seek+12);
 	    CHECK_ERROR (fimp, FALSE);
 	    if (type != 2)
 	    {  /* this is not a playlist MHSD -> skip it */
