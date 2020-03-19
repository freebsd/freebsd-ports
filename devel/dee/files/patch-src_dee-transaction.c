--- src/dee-transaction.c.orig	2012-11-28 08:46:41 UTC
+++ src/dee-transaction.c
@@ -233,7 +233,7 @@ journal_iter_free (JournalIter *jiter)
   g_slice_free (JournalIter, jiter);
 }
 
-#define journal_iter_is_removed(jiter) jiter->change_type == CHANGE_TYPE_REMOVE
+#define journal_iter_is_removed(jiter) (jiter->change_type == CHANGE_TYPE_REMOVE)
 
 static JournalSegment*
 journal_segment_new_before (DeeModelIter *iter, DeeTransaction *txn)
