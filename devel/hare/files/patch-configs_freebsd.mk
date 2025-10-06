--- configs/freebsd.mk.orig	2025-06-21 07:52:26 UTC
+++ configs/freebsd.mk
@@ -2,7 +2,7 @@ MANDIR = $(PREFIX)/share/man
 PREFIX = /usr/local
 BINDIR = $(PREFIX)/bin
 MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
+SRCDIR = $(PREFIX)/share
 STDLIB = $(SRCDIR)/hare/stdlib
 LIBEXECDIR = $(PREFIX)/libexec
 TOOLDIR = $(LIBEXECDIR)/hare
