--- config.example.mk.orig	2023-07-19 01:21:32.000000000 +0200
+++ config.example.mk	2023-07-19 13:07:52.729248178 +0200
@@ -1,21 +1,23 @@
 ## Install configuration
 
-PREFIX = /usr/local
-BINDIR = $(PREFIX)/bin
-MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
+#PREFIX =	%%LOCALBASE%%
+BINDIR = 	$(PREFIX)/bin
+MANDIR =	$(PREFIX)/man
+DATADIR =	$(PREFIX)/share/hare
+SRCDIR =	$(DATADIR)/src
 
 # Where to install the stdlib tree
 STDLIB = $(SRCDIR)/hare/stdlib
 
 # Default HAREPATH
-HAREPATH = $(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-party
+LOCALSRCDIR = ${SRCDIR}/local-src
+HAREPATH = $(LOCALSRCDIR)/stdlib:$(LOCALSRCDIR)/third-party:$(DATADIR)/stdlib:$(DATADIR)/third-party
 
 ## Build configuration
 
 # Platform to build for
-PLATFORM = linux
-ARCH = x86_64
+PLATFORM = freebsd
+#ARCH = x86_64
 
 # External tools and flags
 HAREC = harec
