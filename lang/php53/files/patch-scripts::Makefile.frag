--- scripts/Makefile.frag.orig	Tue Nov 23 14:06:16 2004
+++ scripts/Makefile.frag	Tue Jan 25 08:19:07 2005
@@ -26,18 +26,12 @@
 	/ \
 	Zend/ \
 	TSRM/ \
-	include/ \
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
