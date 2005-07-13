--- pear/Makefile.frag.orig	Tue Sep  2 03:30:13 2003
+++ pear/Makefile.frag	Thu Apr 22 23:52:40 2004
@@ -1,6 +1,7 @@
 # -*- makefile -*-
 
 peardir=$(PEAR_INSTALLDIR)
+XML_RPC_ver=1.3.1
 
 # Skip all php.ini files altogether
 PEAR_INSTALL_FLAGS = -n -dshort_open_tag=0 -dsafe_mode=0
@@ -13,10 +14,18 @@
 
 install-pear:
 	@echo "Installing PEAR environment:      $(INSTALL_ROOT)$(peardir)/"
-	@if $(mkinstalldirs) $(INSTALL_ROOT)$(peardir); then \
-		$(MAKE) -s install-pear-installer install-pear-packages; \
-	else \
-		cat $(srcdir)/install-pear.txt; \
-		exit 5; \
-	fi
+	@$(mkinstalldirs) $(INSTALL_ROOT)$(peardir)/bootstrap \
+		$(INSTALL_ROOT)$(peardir)/bootstrap/Archive \
+		$(INSTALL_ROOT)$(peardir)/bootstrap/Console \
+		$(INSTALL_ROOT)$(peardir)/bootstrap/XML \
+		$(INSTALL_ROOT)$(peardir)/bootstrap/XML/RPC
+	@cp $(srcdir)/PEAR.php $(srcdir)/System.php \
+		$(INSTALL_ROOT)$(peardir)/bootstrap
+	@cp $(srcdir)/Archive/*.php $(INSTALL_ROOT)$(peardir)/bootstrap/Archive
+	@cp $(srcdir)/Console/*.php $(INSTALL_ROOT)$(peardir)/bootstrap/Console
+	@cp -R $(srcdir)/OS $(INSTALL_ROOT)$(peardir)/bootstrap
+	@cp -R $(srcdir)/PEAR $(INSTALL_ROOT)$(peardir)/bootstrap
+	@tar xf $(srcdir)/packages/XML_RPC-$(XML_RPC_ver).tar
+	@cp XML_RPC-$(XML_RPC_ver)/RPC.php $(INSTALL_ROOT)$(peardir)/bootstrap/XML
+	@cp XML_RPC-$(XML_RPC_ver)/Server.php $(INSTALL_ROOT)$(peardir)/bootstrap/XML/RPC
 
