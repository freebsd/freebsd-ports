--- src/irc/flood.cc.orig	2008-07-01 02:53:36.000000000 +0000
+++ src/irc/flood.cc
@@ -204,8 +204,8 @@ void flood_protector::clear_expired(time
 	const seconds_t &max = *std::max_element(vals, vals+n) + 1;
 
 	for (nick_hash_t::const_iterator i = nick_hash.begin(),
-					e = nick_hash.end();
-					i != e;
+					ef = nick_hash.end();
+					i != ef;
 					++i) {
 		flood_entry& e = *i->second;
 
