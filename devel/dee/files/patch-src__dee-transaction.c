--- src/dee-transaction.c.orig	2012-11-28 09:46:41.000000000 +0100
+++ src/dee-transaction.c	2016-01-17 15:50:39.997965000 +0100
@@ -233,7 +233,7 @@ journal_iter_free (JournalIter *jiter)
   g_slice_free (JournalIter, jiter);
 }
 
-#define journal_iter_is_removed(jiter) jiter->change_type == CHANGE_TYPE_REMOVE
+#define journal_iter_is_removed(jiter) (jiter->change_type == CHANGE_TYPE_REMOVE)
 
 static JournalSegment*
 journal_segment_new_before (DeeModelIter *iter, DeeTransaction *txn)
