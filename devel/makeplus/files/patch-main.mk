--- main.mk.orig	Mon Dec 16 15:26:30 2002
+++ main.mk	Fri Dec 27 01:21:12 2002
@@ -33,19 +33,21 @@
 infodir		= $(prefix)/info
 includedir	= $(prefix)/include
 pkgdatadir	= $(datadir)/$(PACKAGE)
+pkgetcdir	= $(sysconfdir)/$(PACKAGE)
 pkglibdir	= $(libdir)/$(PACKAGE)
 pkgincludedir	= $(includedir)/$(PACKAGE)
-mandir		= $(datadir)/man
-man1dir		= $(datadir)/man/man1
-man2dir		= $(datadir)/man/man2
-man3dir		= $(datadir)/man/man3
-man4dir		= $(datadir)/man/man4
-man5dir		= $(datadir)/man/man5
-man6dir		= $(datadir)/man/man6
-man7dir		= $(datadir)/man/man7
-man8dir		= $(datadir)/man/man8
-manndir		= $(datadir)/man/mann
-manldir		= $(datadir)/man/manl
+manprefix	?=$(datadir)
+mandir		= $(manprefix)/man
+man1dir		= $(mandir)/man1
+man2dir		= $(mandir)/man2
+man3dir		= $(mandir)/man3
+man4dir		= $(mandir)/man4
+man5dir		= $(mandir)/man5
+man6dir		= $(mandir)/man6
+man7dir		= $(mandir)/man7
+man8dir		= $(mandir)/man8
+manndir		= $(mandir)/mann
+manldir		= $(mandir)/manl
 
 # Include the other parts of this makefile.
 include $(MAKEPLUS_HOME)/configure.mk
@@ -72,4 +74,4 @@
 .EXPORT_ALL_VARIABLES:
 
 # Phony targets.
-.PHONY: clean distclean
\ No newline at end of file
+.PHONY: clean distclean
