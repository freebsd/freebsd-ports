--- ./extconf.rb.orig	2011-04-06 19:35:39.000000000 +0000
+++ ./extconf.rb	2013-12-18 19:00:54.688254572 +0000
@@ -50,7 +50,7 @@
 rdoc: docs/doc/index.html
 
 docs/doc/index.html: $(RDOC)
-\t@-(cd docs; rdoc .)
+\t@-(cd docs; ${RUBY_RDOC} .)
 
 ri:
 \t@-(rdoc -r docs/*rb)
