--- storage/innobase/buf/buf0buf.cc.orig	2018-03-17 00:16:39.121076000 +0300
+++ storage/innobase/buf/buf0buf.cc	2018-03-17 00:17:08.295213000 +0300
@@ -340,7 +340,7 @@
 	const byte*,
 	buf_chunk_t*,
 	std::less<const byte*>,
-	ut_allocator<std::pair<const byte*, buf_chunk_t*> > >
+	ut_allocator<std::pair<const byte* const, buf_chunk_t*> > >
 	buf_pool_chunk_map_t;
 
 static buf_pool_chunk_map_t*			buf_chunk_map_reg;
