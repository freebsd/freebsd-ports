--- scripts/Makefile.frag.orig	Wed Jun  8 12:34:41 2005
+++ scripts/Makefile.frag	Wed Jul 13 09:28:45 2005
@@ -34,18 +34,9 @@
 	/ \
 	Zend/ \
 	TSRM/ \
-	include/ \
 	main/ \
 	regex/ \
-	ext/iconv/ \
-	ext/pgsql/ \
-	ext/standard/ \
-	ext/session/ \
-	ext/xml/ \
-	ext/xml/expat/ \
-	ext/mbstring/ \
-	ext/mbstring/libmbfl/ \
-	ext/mbstring/libmbfl/mbfl/
+	ext/standard/
 
 install-headers:
 	-@for i in $(HEADER_DIRS); do \
