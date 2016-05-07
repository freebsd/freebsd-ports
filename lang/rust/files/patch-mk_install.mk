--- mk/install.mk.orig	2016-03-01 19:18:54 UTC
+++ mk/install.mk
@@ -15,12 +15,7 @@ RUN_INSTALLER = cd tmp/empty_dir && \
 		--mandir="$(DESTDIR)$(CFG_MANDIR)"
 
 install:
-ifeq (root user, $(USER) $(patsubst %,user,$(SUDO_USER)))
-# Build the dist as the original user
-	$(Q)sudo -u "$$SUDO_USER" $(MAKE) prepare_install
-else
 	$(Q)$(MAKE) prepare_install
-endif
 ifeq ($(CFG_DISABLE_DOCS),)
 	$(Q)$(call RUN_INSTALLER,$(DOC_PKG_NAME)-$(CFG_BUILD)) --disable-ldconfig
 endif
@@ -33,12 +28,7 @@ endif
 prepare_install: dist-tar-bins | tmp/empty_dir
 
 uninstall:
-ifeq (root user, $(USER) $(patsubst %,user,$(SUDO_USER)))
-# Build the dist as the original user
-	$(Q)sudo -u "$$SUDO_USER" $(MAKE) prepare_uninstall
-else
 	$(Q)$(MAKE) prepare_uninstall
-endif
 ifeq ($(CFG_DISABLE_DOCS),)
 	$(Q)$(call RUN_INSTALLER,$(DOC_PKG_NAME)-$(CFG_BUILD)) --uninstall
 endif
