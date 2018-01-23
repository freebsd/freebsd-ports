--- storage/innobase/row/row0sel.cc.orig	2018-01-22 18:12:31.679942000 +0200
+++ storage/innobase/row/row0sel.cc	2018-01-22 18:12:55.834909000 +0200
@@ -5193,7 +5193,7 @@
 		reporting due to search views etc. */
 		if (prev_rec != NULL
 		    && prebuilt->m_mysql_handler->end_range != NULL
-		    && prebuilt->idx_cond == false && end_loop >= 100) {
+		    && prebuilt->idx_cond == NULL && end_loop >= 100) {
 
 			dict_index_t*	key_index = prebuilt->index;
 			bool		clust_templ_for_sec = false;
