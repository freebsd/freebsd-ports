--- scripts/Makefile.frag.orig	Mon Jul 12 19:30:23 2004
+++ scripts/Makefile.frag	Mon Jul 12 19:30:48 2004
@@ -31,11 +31,7 @@
 	regex/ \
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
