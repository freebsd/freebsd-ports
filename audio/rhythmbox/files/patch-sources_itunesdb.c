--- sources/itunesdb.c.orig	Fri Mar 19 12:20:13 2004
+++ sources/itunesdb.c	Fri Apr  2 21:39:39 2004
@@ -729,8 +729,9 @@
       gchar data[4];
       guint32 header_length, entry_length, entry_num, i=0;
       time_t tt = time (NULL);
+      struct tm *tmt;
 
-      localtime (&tt);  /* set the ext. variable 'timezone' (see below) */
+      tmt = localtime (&tt);  /* set the ext. variable 'timezone' (see below) */
       if (seek_get_n_bytes (plycts, data, 0, 4) != 4)  break;
       if (cmp_n_bytes (data, "mhdp", 4) == FALSE)      break;
       header_length = get4int (plycts, 4);
@@ -768,7 +769,7 @@
 	   * way to do that ?
 	   */
 	  if (playcount->time_played)
-	      playcount->time_played += __timezone;
+	      playcount->time_played += tmt->tm_gmtoff;
 
 	  /* rating only exists if the entry length is at least 0x10 */
 	  if (entry_length >= 0x10)
