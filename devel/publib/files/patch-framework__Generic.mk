--- ./framework/Generic.mk.orig	2006-03-12 06:04:21.000000000 -0500
+++ ./framework/Generic.mk	2014-08-05 05:46:03.000000000 -0400
@@ -43,12 +43,10 @@
 pre-install post-install:
 	@true
 install:
-	$(INSTALL) -d "$(man3dir)"
+	$(INSTALL) -d "$(DESTDIR)$(man3dir)"
 	for i in $(srcdir)/*.3; do \
 		if test -f $$i; then \
-		t="$(man3dir)/`basename $$i .3`.$(man3ext)"; \
+		t="$(DESTDIR)$(man3dir)/`basename $$i .3`.$(man3ext)"; \
 		$(INSTALL_MAN) $$i "$$t"; \
-		gzip -9f "$$t"; \
-		sh $(fwdir)/link-alternative-names $$t $(man3dir) $(man3ext); \
 		fi; \
 	done
