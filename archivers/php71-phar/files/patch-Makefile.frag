--- Makefile.frag.orig	2017-12-05 11:59:48 UTC
+++ Makefile.frag
@@ -1,5 +1,5 @@
 $(srcdir)/phar_path_check.c: $(srcdir)/phar_path_check.re
-	@(cd $(top_srcdir); $(RE2C) --no-generation-date -b -o ext/phar/phar_path_check.c ext/phar/phar_path_check.re)
+	@(cd $(top_srcdir); $(RE2C) --no-generation-date -b -o phar_path_check.c phar_path_check.re)
 
 pharcmd: $(builddir)/phar.php $(builddir)/phar.phar
 
