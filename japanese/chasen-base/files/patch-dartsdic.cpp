--- lib/dartsdic.cpp.orig	2008-12-26 15:45:32.000000000 +0000
+++ lib/dartsdic.cpp	2008-12-26 15:46:13.000000000 +0000
@@ -168,7 +168,7 @@
 {
     Hash::iterator i, last;
     Hash* entries = builder->entries;
-    char** keys = new char*[entries->size()];
+    const char** keys = new const char*[entries->size()];
     size_t* lens = new size_t[entries->size()];
     long* vals = new long[entries->size()];
     int size = 0;
@@ -185,7 +185,7 @@
 	    lex_indices.push_back(i->second);
 	}
 	lens[size] = key.size();
-	keys[size] = (char*) key.data();
+	keys[size] = (const char*) key.data();
 	vals[size] = redump_lex(lens[size], lex_indices, tmpfile, lexfile);
 	if (vals[size] < 0) {
 	    std::cerr << "Unexpected error at " << key << std::endl;
