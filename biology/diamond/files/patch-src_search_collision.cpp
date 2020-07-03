--- src/search/collision.cpp.orig	2020-07-03 10:58:27 UTC
+++ src/search/collision.cpp
@@ -92,7 +92,6 @@ bool is_primary_hit(const Letter *query,
 	const unsigned sid,
 	const unsigned len)
 {
-	assert(len > 0 && len <= config.window * 2);
 	const bool chunked(config.lowmem > 1);
 	uint64_t mask = reduced_match32(query, subject, len);
 	unsigned i = 0;
