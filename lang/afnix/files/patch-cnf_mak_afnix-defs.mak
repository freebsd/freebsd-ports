--- cnf/mak/afnix-defs.mak.orig	Wed Feb 16 19:35:18 2005
+++ cnf/mak/afnix-defs.mak	Wed Feb 16 19:37:55 2005
@@ -58,10 +58,10 @@
 BINDIR		= $(PREFIX)/bin
 LIBDIR		= $(PREFIX)/lib
 SHARED		= $(PREFIX)/share
-HDRDIR		= $(SHARED)/include/afnix
+HDRDIR		= $(PREFIX)/include/afnix
 DOCDIR		= $(SHARED)/doc/afnix
-MANDIR		= $(SHARED)/man
-ETCDIR		= $(SHARED)/etc/afnix
+MANDIR		= $(PREFIX)/man
+ETCDIR		= $(SHARED)/doc/afnix
 
 # ----------------------------------------------------------------------------
 # - other shared commands and scripts                                        -
