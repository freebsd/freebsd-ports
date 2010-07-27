--- sapi/fpm/Makefile.frag.orig	2010-07-27 15:57:32.000000000 +0200
+++ sapi/fpm/Makefile.frag	2010-07-27 15:57:06.000000000 +0200
@@ -3,14 +3,14 @@
 $(builddir)/fpm: 
 	@mkdir -p $(builddir)/fpm
 
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
