--- cnf/mak/afnix-defs.mak.orig	Wed Feb 16 19:35:18 2005
+++ cnf/mak/afnix-defs.mak	Wed Feb 16 19:37:55 2005
@@ -58,9 +58,9 @@
 BINDIR		= $(PREFIX)/bin
 LIBDIR		= $(PREFIX)/lib
 HDRDIR		= $(SHRDIR)/include/afnix
-DOCDIR		= $(SHRDIR)/doc/afnix
+DOCDIR		= $(SHRDIR)/share/doc/afnix
 MANDIR		= $(SHRDIR)/man
-ETCDIR		= $(SHRDIR)/etc/afnix
+ETCDIR		= $(SHRDIR)/share/doc/afnix
 
 # ----------------------------------------------------------------------------
 # - other shared commands and scripts                                        -
