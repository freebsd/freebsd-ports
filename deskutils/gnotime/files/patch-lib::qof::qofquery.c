--- lib/qof/qofquery.c.orig	Wed Jul  7 22:39:18 2004
+++ lib/qof/qofquery.c	Wed Jul  7 22:39:27 2004
@@ -1216,13 +1216,13 @@
 
 void qof_query_set_book (QofQuery *q, QofBook *book)
 {
+  GSList *slist = NULL;
   if (!q || !book) return;
 
   /* Make sure this book is only in the list once */
   if (g_list_index (q->books, book) == -1)
     q->books = g_list_prepend (q->books, book);
 
-  GSList *slist = NULL;
   g_slist_prepend (slist, QOF_PARAM_GUID);
   g_slist_prepend (slist, QOF_PARAM_BOOK);
   qof_query_add_guid_match (q, slist,
