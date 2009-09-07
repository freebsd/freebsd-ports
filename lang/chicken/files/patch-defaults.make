--- ./defaults.make.orig	2009-07-31 19:13:36.000000000 -0300
+++ ./defaults.make	2009-09-06 19:03:43.000000000 -0300
@@ -43,6 +43,7 @@
 SRCDIR ?= .$(SEP)
 DESTDIR ?=
 PREFIX ?= /usr/local
+LOCALBASE ?= /usr/local
 
 BINDIR = $(PREFIX)/bin
 LIBDIR = $(PREFIX)/lib
@@ -51,7 +52,7 @@
 TOPMANDIR = $(SHAREDIR)/man
 MANDIR = $(TOPMANDIR)/man1
 INCDIR = $(PREFIX)/include
-DOCDIR = $(DATADIR)/doc
+DOCDIR = $(SHAREDIR)/doc/chicken
 CHICKENLIBDIR = $(LIBDIR)/chicken
 EGGDIR = $(CHICKENLIBDIR)/$(BINARYVERSION)
 
