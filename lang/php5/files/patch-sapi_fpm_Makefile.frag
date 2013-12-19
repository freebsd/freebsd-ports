--- sapi/fpm/Makefile.frag.orig	2013-12-10 19:32:43.000000000 +0000
+++ sapi/fpm/Makefile.frag	2013-12-13 21:55:54.402236058 +0000
@@ -18,6 +18,6 @@ install-fpm: $(SAPI_FPM_PATH)
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man8
 	@$(INSTALL_DATA) sapi/fpm/php-fpm.8 $(INSTALL_ROOT)$(mandir)/man8/php-fpm$(program_suffix).8
 
-	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/fpm/"
-	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/fpm
-	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/fpm/status.html
+	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/php/fpm/"
+	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/php/fpm
+	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/php/fpm/status.html
