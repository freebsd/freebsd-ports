--- framework/Generic.mk.orig	Tue Jan 11 00:49:05 2005
+++ framework/Generic.mk	Tue Jan 11 00:50:08 2005
@@ -48,7 +48,5 @@
 		if test -f $$i; then \
 		t="$(man3dir)/`basename $$i .3`.$(man3ext)"; \
 		$(INSTALL_MAN) $$i "$$t"; \
-		gzip -9f "$$t"; \
-		sh $(fwdir)/link-alternative-names $$t $(man3dir) $(man3ext); \
 		fi; \
 	done
