--- lib/dartsdic.cpp.orig	2003-07-30 18:06:57.000000000 +0200
+++ lib/dartsdic.cpp	2008-06-22 21:44:25.000000000 +0200
@@ -68,7 +68,7 @@
 
     da = (darts_t*)cha_malloc(sizeof(darts_t));
     da->da_mmap = cha_mmap_file(daname);
-    darts->setArray(cha_mmap_map(da->da_mmap));
+    darts->set_array(cha_mmap_map(da->da_mmap));
     da->da = darts;
     da->lex_mmap = cha_mmap_file(lexname);
     da->dat_mmap = cha_mmap_file(datname);
@@ -160,7 +160,7 @@
 {
     Hash::iterator i, last;
     Hash* entries = builder->entries;
-    char** keys = new char*[entries->size()];
+    const char** keys = new const char*[entries->size()];
     size_t* lens = new size_t[entries->size()];
     long* vals = new long[entries->size()];
     int size = 0;
@@ -177,7 +177,7 @@
 	    lex_indices.push_back(i->second);
 	}
 	lens[size] = key.size();
-	(const char*)keys[size] = key.data();
+	keys[size] = (const char*) key.data();
 	vals[size] = redump_lex(lens[size], lex_indices, tmpfile, lexfile);
 	if (vals[size] < 0) {
 	    std::cerr << "Unexpected error at " << key << std::endl;
