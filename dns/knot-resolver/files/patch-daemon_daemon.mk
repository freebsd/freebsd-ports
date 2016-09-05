--- daemon/daemon.mk.orig	2016-08-24 12:05:47 UTC
+++ daemon/daemon.mk
@@ -46,8 +46,8 @@ daemon: $(kresd)
 daemon-install: kresd-install bindings-install
 ifneq ($(SED),)
 	$(SED) -e "s/@VERSION@/$(MAJOR).$(MINOR).$(PATCH)/" -e "s/@DATE@/$(date)/" doc/kresd.8.in > doc/kresd.8
-	$(INSTALL) -d -m 0755 $(DESTDIR)$(PREFIX)/share/man/man8/
-	$(INSTALL) -m 0644 doc/kresd.8 $(DESTDIR)$(PREFIX)/share/man/man8/
+	$(INSTALL) -d -m 0755 $(DESTDIR)$(PREFIX)/man/man8/
+	$(INSTALL) -m 0644 doc/kresd.8 $(DESTDIR)$(PREFIX)/man/man8/
 endif
 daemon-clean: kresd-clean
 	@$(RM) daemon/lua/*.inc
