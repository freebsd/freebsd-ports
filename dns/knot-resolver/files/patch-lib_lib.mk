--- lib/lib.mk.orig	2016-08-24 12:05:47 UTC
+++ lib/lib.mk
@@ -83,8 +83,8 @@ libkres.pc:
 	@echo 'Libs: -L$${libdir} -lkres' >> $@
 	@echo 'Cflags: -I$${includedir}' >> $@
 libkres-pcinstall: libkres.pc libkres-install
-	$(INSTALL) -d -m 755 $(DESTDIR)$(LIBDIR)/pkgconfig/
-	$(INSTALL)    -m 644 $< $(DESTDIR)$(LIBDIR)/pkgconfig/
+	$(INSTALL) -d -m 755 $(DESTDIR)$(PKG_CONFIG_PATH)/
+	$(INSTALL)    -m 644 $< $(DESTDIR)$(PKG_CONFIG_PATH)/
 
 # Targets
 lib: $(libkres)
