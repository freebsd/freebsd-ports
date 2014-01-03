--- ./extconf.rb.orig	2011-04-06 19:35:39.000000000 +0000
+++ ./extconf.rb	2014-01-03 01:45:56.334209519 +0000
@@ -50,7 +50,7 @@
 rdoc: docs/doc/index.html
 
 docs/doc/index.html: $(RDOC)
-\t@-(cd docs; rdoc .)
+\t@-(cd docs; ${RUBY_RDOC} .)
 
 ri:
 \t@-(rdoc -r docs/*rb)
