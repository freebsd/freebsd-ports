--- storage/innobase/row/row0sel.cc.orig	2018-08-27 16:21:56 UTC
+++ storage/innobase/row/row0sel.cc
@@ -5175,7 +5175,7 @@ rec_loop:
 		reporting due to search views etc. */
 		if (prev_rec != NULL
 		    && prebuilt->m_mysql_handler->end_range != NULL
-		    && prebuilt->idx_cond == false && end_loop >= 100) {
+		    && prebuilt->idx_cond == NULL && end_loop >= 100) {
 
 			dict_index_t*	key_index = prebuilt->index;
 			bool		clust_templ_for_sec = false;
