--- storage/innobase/buf/buf0buf.cc.orig	2016-03-28 18:06:12 UTC
+++ storage/innobase/buf/buf0buf.cc
@@ -338,7 +338,7 @@ typedef std::map<
 	const byte*,
 	buf_chunk_t*,
 	std::less<const byte*>,
-	ut_allocator<std::pair<const byte*, buf_chunk_t*> > >
+	ut_allocator<std::pair<const byte* const, buf_chunk_t*> > >
 	buf_pool_chunk_map_t;
 
 static buf_pool_chunk_map_t*			buf_chunk_map_reg;
