--- storage/innobase/dict/dict0stats.cc.orig	2018-03-17 00:37:34.099255000 +0300
+++ storage/innobase/dict/dict0stats.cc	2018-03-17 00:37:59.009449000 +0300
@@ -139,7 +139,7 @@
 typedef std::vector<ib_uint64_t, ut_allocator<ib_uint64_t> >	boundaries_t;
 
 /** Allocator type used for index_map_t. */
-typedef ut_allocator<std::pair<const char*, dict_index_t*> >
+typedef ut_allocator<std::pair<const char* const, dict_index_t*> >
 	index_map_t_allocator;
 
 /** Auxiliary map used for sorting indexes by name in dict_stats_save(). */
