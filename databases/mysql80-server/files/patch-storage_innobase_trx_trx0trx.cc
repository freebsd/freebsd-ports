--- storage/innobase/trx/trx0trx.cc.orig	2017-01-05 15:43:29 UTC
+++ storage/innobase/trx/trx0trx.cc
@@ -63,7 +63,7 @@ typedef std::set<
 typedef std::map<
 	trx_t*, table_id_set,
 	std::less<trx_t*>,
-	ut_allocator<table_id_set> >	trx_table_map;
+	ut_allocator<std::pair<trx_t* const, table_id_set>> >	trx_table_map;
 
 /** Map of resurrected transactions to affected table_id */
 static trx_table_map	resurrected_trx_tables;
