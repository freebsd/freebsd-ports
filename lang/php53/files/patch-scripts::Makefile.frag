--- scripts/Makefile.frag.orig	Mon Jun 28 10:41:39 2004
+++ scripts/Makefile.frag	Mon Jun 28 10:47:24 2004
@@ -29,12 +29,15 @@
 	main/ \
 	main/streams/ \
 	regex/ \
+	ext/gd/ \
+	ext/gd/libgd/ \
 	ext/libxml/ \
 	ext/standard/ \
 	ext/session/ \
 	ext/xml/ \
-	ext/xml/expat/ \
 	ext/mbstring/ \
+	ext/mbstring/libmbfl/ \
+	ext/mbstring/libmbfl/mbfl/ \
 	ext/sqlite/libsqlite/src/sqlite.h
 
 install-headers:
