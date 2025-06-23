--- configs/freebsd.mk.orig	2025-06-21 07:52:26 UTC
+++ configs/freebsd.mk
@@ -1,27 +1,28 @@
 # install locations
-PREFIX = /usr/local
-BINDIR = $(PREFIX)/bin
-MANDIR = $(PREFIX)/share/man
-SRCDIR = $(PREFIX)/src
-STDLIB = $(SRCDIR)/hare/stdlib
-LIBEXECDIR = $(PREFIX)/libexec
-TOOLDIR = $(LIBEXECDIR)/hare
+PREFIX ?= /usr/local
+BINDIR ?= $(PREFIX)/bin
+MANDIR ?= $(PREFIX)/share/man
+DATADIR ?= $(PREFIX)/share/hare
+SRCDIR ?= $(DATADIR)/src
+STDLIB ?= $(DATADIR)/stdlib
+LIBEXECDIR ?= $(PREFIX)/libexec
+TOOLDIR ?= $(LIBEXECDIR)/hare
 
 # variables used during build
 PLATFORM = freebsd
 ARCH = x86_64
 HAREFLAGS =
-HARECFLAGS =
+HARECFLAGS = -a ${ARCH}
 QBEFLAGS =
 ASFLAGS =
-LDLINKFLAGS = --gc-sections -z noexecstack
+LDLINKFLAGS ?= --gc-sections -z noexecstack
 
 # commands used by the build script
-HAREC = harec
-QBE = qbe
-AS = as
-LD = ld
-SCDOC = scdoc
+HAREC ?= harec
+QBE ?= qbe
+AS ?= as
+LD ?= ld
+SCDOC ?= scdoc
 
 # build locations
 HARECACHE = .cache
@@ -29,17 +30,17 @@ HAREPATH = $(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-
 
 # variables that will be embedded in the binary with -D definitions
 HAREPATH = $(SRCDIR)/hare/stdlib:$(SRCDIR)/hare/third-party
-VERSION=$$(./scripts/version)
+VERSION ?= $$(./scripts/version)
 
 # For cross-compilation, modify the variables below
-AARCH64_AS=as
-AARCH64_CC=cc
-AARCH64_LD=ld
+AARCH64_AS ?= as
+AARCH64_CC ?= cc
+AARCH64_LD ?= ld
 
-RISCV64_AS=as
-RISCV64_CC=cc
-RISCV64_LD=ld
+RISCV64_AS ?= as
+RISCV64_CC ?= cc
+RISCV64_LD ?= ld
 
-X86_64_AS=as
-X86_64_CC=cc
-X86_64_LD=ld
+X86_64_AS ?= as
+X86_64_CC ?= cc
+X86_64_LD ?= ld
