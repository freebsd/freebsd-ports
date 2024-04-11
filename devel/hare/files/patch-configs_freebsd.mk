--- configs/freebsd.mk.orig	2024-02-16 09:48:20 UTC
+++ configs/freebsd.mk
@@ -1,15 +1,16 @@
 # install locations
-PREFIX = /usr/local
-BINDIR = $(PREFIX)/bin
-MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
-STDLIB = $(SRCDIR)/hare/stdlib
+#PREFIX =	%%LOCALBASE%%
+BINDIR = 	$(PREFIX)/bin
+MANDIR =	$(PREFIX)/share/man
+DATADIR =	$(PREFIX)/share/hare
+SRCDIR =	$(DATADIR)/src
+STDLIB =	$(DATADIR)/stdlib
 
 # variables used during build
 PLATFORM = freebsd
 ARCH = x86_64
 HAREFLAGS =
-HARECFLAGS =
+HARECFLAGS = -a ${ARCH}
 QBEFLAGS =
 ASFLAGS =
 LDLINKFLAGS = --gc-sections -z noexecstack
@@ -26,7 +27,9 @@ BINOUT = .bin
 BINOUT = .bin
 
 # variables that will be embedded in the binary with -D definitions
-HAREPATH = $(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-party
+#LOCALSRCDIR = ${SRCDIR}/local-src
+#HAREPATH = $(LOCALSRCDIR)/stdlib:$(LOCALSRCDIR)/third-party:$(DATADIR)/stdlib:$(DATADIR)/third-party
+HAREPATH = $(DATADIR)/stdlib:$(DATADIR)/third-party
 VERSION=$$(./scripts/version)
 
 # For cross-compilation, modify the variables below
