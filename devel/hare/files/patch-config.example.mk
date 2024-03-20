--- config.example.mk.orig	2023-07-18 23:21:32 UTC
+++ config.example.mk
@@ -1,21 +1,23 @@
 ## Install configuration
 
-PREFIX = /usr/local
-BINDIR = $(PREFIX)/bin
-MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
+#PREFIX =	%%LOCALBASE%%
+BINDIR = 	$(PREFIX)/bin
+MANDIR =	$(PREFIX)/share/man
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
