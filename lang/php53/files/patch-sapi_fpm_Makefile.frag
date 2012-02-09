--- sapi/fpm/Makefile.frag.orig	2011-10-08 23:04:10.000000000 +0200
+++ sapi/fpm/Makefile.frag	2012-02-09 16:43:25.000000000 +0100
@@ -4,14 +4,14 @@
 	@mkdir -p $(builddir)/fpm
 	@mkdir -p $(builddir)/fpm/events
 
-$(SAPI_FPM_PATH): $(builddir)/fpm $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(SAPI_EXTRA_DEPS)
+$(SAPI_FPM_PATH): $(builddir)/fpm $(PHP_GLOBAL_OBJS) $(PHP_FPM_OBJS) $(FPM_EXTRA_DEPS)
 	$(BUILD_FPM)
 
 $(builddir)/fpm/fpm_conf.lo: $(builddir)/../../main/build-defs.h
 
 install-build: install-fpm
 
-install-fpm: install-sapi
+install-fpm:
 	@echo "Installing PHP FPM binary:        $(INSTALL_ROOT)$(sbindir)/"
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(sbindir)
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(localstatedir)/log
@@ -27,6 +27,6 @@
 	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man8
 	@$(INSTALL_DATA) sapi/fpm/php-fpm.8 $(INSTALL_ROOT)$(mandir)/man8/php-fpm$(program_suffix).8
 
-	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/fpm/"
-	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/fpm
-	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/fpm/status.html
+	@echo "Installing PHP FPM status page:      $(INSTALL_ROOT)$(datadir)/php/fpm/"
+	@$(mkinstalldirs) $(INSTALL_ROOT)$(datadir)/php/fpm
+	@$(INSTALL_DATA) sapi/fpm/status.html $(INSTALL_ROOT)$(datadir)/php/fpm/status.html
