--- scripts/Makefile.frag.orig	Tue Nov 23 14:06:16 2004
+++ scripts/Makefile.frag	Thu Dec 16 13:00:26 2004
@@ -30,14 +30,9 @@
 	main/ \
 	main/streams/ \
 	regex/ \
-	ext/iconv/ \
 	ext/libxml/ \
 	ext/standard/ \
-	ext/session/ \
-	ext/xml/ \
-	ext/xml/expat/ \
-	ext/mbstring/ \
-	ext/sqlite/libsqlite/src/sqlite.h
+	ext/spl/
 
 install-headers:
 	-@for i in $(HEADER_DIRS); do \
