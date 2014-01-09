--- cnf/mak/afnix-defs.mak.orig	2014-01-02 15:24:19.000000000 +0100
+++ cnf/mak/afnix-defs.mak	2014-01-08 15:26:18.000000000 +0100
@@ -58,14 +58,14 @@ BLDDEB		= $(BLDPKG)/deb/afnix-$(VERSION)
 # - install path definition                                                  -
 # ----------------------------------------------------------------------------
 
-BINDIR		= $(PREFIX)/bin
-LIBDIR		= $(PREFIX)/lib
-PRJDIR		= $(PREFIX)/lib/afnix
-HDRDIR		= $(PREFIX)/include/afnix
-DOCDIR		= $(SHRDIR)/doc/afnix
-MANDIR		= $(SHRDIR)/man
-ETCDIR		= $(ALTDIR)/etc/afnix
-WWWDIR		= $(ALTDIR)/var/www/afnix
+BINDIR		= $(DESTDIR)$(PREFIX)/bin
+LIBDIR		= $(DESTDIR)$(PREFIX)/lib
+PRJDIR		= $(DESTDIR)$(PREFIX)/lib/afnix
+HDRDIR		= $(DESTDIR)$(PREFIX)/include/afnix
+DOCDIR		= $(DESTDIR)$(SHRDIR)/doc/afnix
+MANDIR		= $(DESTDIR)$(MANPREFIX)/man
+ETCDIR		= $(DESTDIR)$(ALTDIR)/etc/afnix
+WWWDIR		= $(DESTDIR)$(ALTDIR)/var/www/afnix
 
 # ----------------------------------------------------------------------------
 # - other shared commands and scripts                                        -
