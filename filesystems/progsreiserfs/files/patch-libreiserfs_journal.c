--- libreiserfs/journal.c.orig	2002-12-12 12:32:35 UTC
+++ libreiserfs/journal.c
@@ -482,7 +482,7 @@ static int callback_journal_replay(reise
 blk_t reiserfs_journal_boundary_transactions(reiserfs_journal_t *journal,
     reiserfs_journal_trans_t *oldest, reiserfs_journal_trans_t *newest)
 {
-    reiserfs_gauge_t *gauge;
+    reiserfs_gauge_t *gauge = NULL;
     struct reiserfs_replay_desc desc;
 	
     desc.oldest_id = 0xffffffff; desc.newest_id = 0x0;
