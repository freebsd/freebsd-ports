--- storage/innobase/trx/trx0purge.cc.orig	2017-01-05 13:57:29 UTC
+++ storage/innobase/trx/trx0purge.cc
@@ -1668,7 +1668,7 @@ trx_purge_attach_undo_recs(
 	using GroupBy = std::map<
 		table_id_t, purge_node_t::Recs*,
 		std::less<table_id_t>,
-		mem_heap_allocator<std::pair<table_id_t, purge_node_t::Recs*>>>;
+		mem_heap_allocator<std::pair<const table_id_t, purge_node_t::Recs*>>>;
 
 	GroupBy		group_by{
 		GroupBy::key_compare{},
