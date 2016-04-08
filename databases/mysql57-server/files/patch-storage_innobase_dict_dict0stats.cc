--- storage/innobase/dict/dict0stats.cc.orig	2015-11-29 19:16:24 UTC
+++ storage/innobase/dict/dict0stats.cc
@@ -139,7 +139,7 @@ then we would store 5,7,10,11,12 in the 
 typedef std::vector<ib_uint64_t, ut_allocator<ib_uint64_t> >	boundaries_t;
 
 /** Allocator type used for index_map_t. */
-typedef ut_allocator<std::pair<const char*, dict_index_t*> >
+typedef ut_allocator<std::pair<const char* const, dict_index_t*> >
 	index_map_t_allocator;
 
 /** Auxiliary map used for sorting indexes by name in dict_stats_save(). */
