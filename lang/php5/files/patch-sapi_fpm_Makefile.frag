--- sapi/fpm/Makefile.frag.orig	2011-10-08 23:04:10.000000000 +0200
+++ sapi/fpm/Makefile.frag	2012-02-09 16:43:25.000000000 +0100
@@ -27,6 +27,6 @@
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man8
 	@$(INSTALL_DATA) sapi/fpm/php-fpm.8 $(INSTALL_ROOT)$(mandir)/man8/php-fpm$(program_suffix).8
 
-	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/fpm/"
-	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/fpm
-	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/fpm/status.html
+	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/php/fpm/"
+	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/php/fpm
+	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/php/fpm/status.html
