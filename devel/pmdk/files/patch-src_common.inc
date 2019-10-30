--- src/common.inc.orig	2019-08-27 15:43:26 UTC
+++ src/common.inc
@@ -193,9 +193,9 @@ else
 export WSTRINGOP_TRUNCATION_AVAILABLE
 endif
 
-install_recursive = $(shell cd $(1) && find . -type f -exec install -m $(2) -D {} $(3)/{} \;)
+install_recursive = $(shell cd $(1) && find . -type d -exec install -d $(3)/{} \; && find . -type f -exec install -m $(2) {} $(3)/{} \;)
 
-install_recursive_filter = $(shell cd $(1) && find . -type f -name "$(2)" -exec install -m $(3) -D {} $(4)/{} \;)
+install_recursive_filter = $(shell cd $(1) && find . -type d -exec install -d $(4)/{} \; && find . -type f -name "$(2)" -exec install -m $(3) {} $(4)/{} \;)
 
 define create-deps
 	@cp $(objdir)/$*.d $(objdir)/.deps/$*.P; \
@@ -216,7 +216,7 @@ export prefix = /usr/local
 export exec_prefix := $(prefix)
 export sysconfdir := $(prefix)/etc
 export datarootdir := $(prefix)/share
-export mandir := $(datarootdir)/man
+export mandir := $(MANPREFIX)/man
 export docdir := $(datarootdir)/doc
 export man1dir := $(mandir)/man1
 export man3dir := $(mandir)/man3
