--- lib/dartsdic.cpp.orig	Sat Aug 14 12:10:21 2004
+++ lib/dartsdic.cpp	Sat Aug 14 12:10:26 2004
@@ -177,7 +177,7 @@
 	    lex_indices.push_back(i->second);
 	}
 	lens[size] = key.size();
-	(const char*)keys[size] = key.data();
+	keys[size] = (char*) key.data();
 	vals[size] = redump_lex(lens[size], lex_indices, tmpfile, lexfile);
 	if (vals[size] < 0) {
 	    std::cerr << "Unexpected error at " << key << std::endl;
