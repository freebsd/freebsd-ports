--- pear/Makefile.frag.orig	Sat Apr 12 01:48:37 2003
+++ pear/Makefile.frag	Sat May 17 10:08:54 2003
@@ -13,10 +13,13 @@
 
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
+		$(INSTALL_ROOT)$(peardir)/bootstrap/Console
+	@cp $(srcdir)/PEAR.php $(srcdir)/System.php \
+		$(INSTALL_ROOT)$(peardir)/bootstrap
+	@cp $(srcdir)/Archive/*.php $(INSTALL_ROOT)$(peardir)/bootstrap/Archive
+	@cp $(srcdir)/Console/*.php $(INSTALL_ROOT)$(peardir)/bootstrap/Console
+	@cp -R $(srcdir)/OS $(INSTALL_ROOT)$(peardir)/bootstrap
+	@cp -R $(srcdir)/PEAR $(INSTALL_ROOT)$(peardir)/bootstrap
 
