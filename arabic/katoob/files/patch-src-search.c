--- src/search.c	Tue Aug 26 07:54:37 2003
+++ src/search.c.patch	Mon May 24 17:07:16 2004
@@ -266,9 +266,8 @@
   tmp = katoob_document_get_last_replaced (doc);
   if ((tmp) && (replace))
     {
-      gtk_entry_set_text (GTK_ENTRY (entry2), g_strdup (tmp));
-      g_free (tmp);
-      tmp = NULL;
+	gtk_entry_set_text (GTK_ENTRY (entry2), tmp);
+	tmp = NULL;
     }
 }
 
