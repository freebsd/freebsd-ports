--- sapi/fpm/Makefile.frag.orig	2012-02-08 15:48:16.000000000 +0100
+++ sapi/fpm/Makefile.frag	2012-02-08 15:48:44.000000000 +0100
@@ -27,6 +27,6 @@
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man8
 	@$(INSTALL_DATA) sapi/fpm/php-fpm.8 $(INSTALL_ROOT)$(mandir)/man8/php-fpm$(program_suffix).8
 
-	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/fpm/"
-	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/fpm
-	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/fpm/status.html
+	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/php/fpm/"
+	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/php/fpm
+	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/php/fpm/status.html
