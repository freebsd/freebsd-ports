
$FreeBSD$

--- listing.c.orig
+++ listing.c
@@ -192,7 +192,7 @@
     else if (typ == OUT_RESERVE) 
     {
 	char q[20];
-	sprintf(q, "<res %08lX>", size);
+	snprintf(q, sizeof(q), "<res %08lX>", size);
 	list_out (offset, q);
     }
 }
