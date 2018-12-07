--- src/common.inc.orig	2018-10-26 15:43:47 UTC
+++ src/common.inc
@@ -85,9 +85,7 @@ endif
 osdep = $(1)_$(shell echo $(OS_KERNEL_NAME) | tr "[:upper:]" "[:lower:]")$(2)
 
 get_arch = $(shell $(CC) -dumpmachine | awk -F'[/-]' '{print $$1}')
-ifeq ($(ARCH),)
-export ARCH := $(call get_arch)
-endif
+override export ARCH := $(call get_arch)
 
 ifeq ($(PKG_CONFIG_CHECKED),)
 ifeq ($(shell command -v $(PKG_CONFIG) && echo y || echo n), n)
@@ -186,9 +184,9 @@ else
 export WSTRINGOP_TRUNCATION_AVAILABLE
 endif
 
-install_recursive = $(shell cd $(1) && find . -type f -exec install -m $(2) -D {} $(3)/{} \;)
+install_recursive = $(shell cd $(1) && find . -type d -exec install -d $(3)/{} \; && find . -type f -exec install -m $(2) {} $(3)/{} \;)
 
-install_recursive_filter = $(shell cd $(1) && find . -type f -name "$(2)" -exec install -m $(3) -D {} $(4)/{} \;)
+install_recursive_filter = $(shell cd $(1) && find . -type d -exec install -d $(4)/{} \; && find . -type f -name "$(2)" -exec install -m $(3) {} $(4)/{} \;)
 
 define create-deps
 	@cp $(objdir)/$*.d $(objdir)/.deps/$*.P; \
@@ -209,7 +207,7 @@ export prefix = /usr/local
 export exec_prefix := $(prefix)
 export sysconfdir := $(prefix)/etc
 export datarootdir := $(prefix)/share
-export mandir := $(datarootdir)/man
+export mandir := $(MANPREFIX)/man
 export docdir := $(datarootdir)/doc
 export man1dir := $(mandir)/man1
 export man3dir := $(mandir)/man3
