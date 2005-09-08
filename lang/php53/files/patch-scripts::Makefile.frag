--- scripts/Makefile.frag.orig	Tue Jun  7 23:57:06 2005
+++ scripts/Makefile.frag	Wed Sep  7 17:50:23 2005
@@ -34,21 +34,12 @@
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
-	ext/dom/xml_common.h \
-	ext/xml/ \
-	ext/xml/expat/ \
-	ext/mbstring/ \
-	ext/mbstring/libmbfl/ \
-	ext/mbstring/libmbfl/mbfl/ \
-	ext/sqlite/libsqlite/src/sqlite.h
+	ext/spl/
 
 install-headers:
 	-@for i in $(HEADER_DIRS); do \
