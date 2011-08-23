--- extconf.rb.orig	2011-08-22 22:53:57.000000000 -0700
+++ extconf.rb	2011-08-22 22:54:10.000000000 -0700
@@ -50,7 +50,7 @@
 rdoc: docs/doc/index.html
 
 docs/doc/index.html: $(RDOC)
-\t@-(cd docs; rdoc .)
+\t@-(cd docs; ${RUBY_RDOC} .)
 
 ri:
 \t@-(rdoc -r docs/*rb)
