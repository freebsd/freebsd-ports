--- defaults.make.orig	2010-03-29 14:43:35.000000000 +0000
+++ defaults.make	2010-03-29 14:44:24.000000000 +0000
@@ -43,6 +43,7 @@
 SRCDIR ?= .$(SEP)
 DESTDIR ?=
 PREFIX ?= /usr/local
+LOCALBASE ?= /usr/local
 BRANCHNAME ?= $(shell scripts/identify-branch $(SRCDIR))
 
 BINDIR = $(PREFIX)/bin
@@ -52,7 +53,7 @@
 TOPMANDIR = $(SHAREDIR)/man
 MANDIR = $(TOPMANDIR)/man1
 INCDIR = $(PREFIX)/include
-DOCDIR = $(DATADIR)/doc
+DOCDIR = $(SHAREDIR)/doc/chicken
 VARDIR ?= $(LIBDIR)
 CHICKENLIBDIR = $(VARDIR)/chicken
 EGGDIR = $(CHICKENLIBDIR)/$(BINARYVERSION)
