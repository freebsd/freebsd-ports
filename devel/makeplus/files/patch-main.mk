
$FreeBSD$

--- main.mk.orig	Sat Mar  1 15:42:02 2003
+++ main.mk	Tue Jul  1 15:49:10 2003
@@ -33,13 +33,14 @@
 infodir		= $(prefix)/info
 includedir	= $(prefix)/include
 pkgdatadir	= $(datadir)/$(PACKAGE)
-docdir		= $(datadir)/doc/$(PACKAGE)-$(VERSION)
 pkgetcdir	= $(sysconfdir)/$(PACKAGE)
 pkglibdir	= $(libdir)/$(PACKAGE)
 pkgincludedir	= $(includedir)/$(PACKAGE)
 ifneq ($(shell uname), FreeBSD)
+docdir		= $(datadir)/doc/$(PACKAGE)-$(VERSION)
 manprefix	= $(datadir)
 else
+docdir		= $(datadir)/doc/$(PACKAGE)
 manprefix	= $(prefix)
 endif
 mandir		= $(manprefix)/man
