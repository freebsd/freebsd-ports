--- Make.inc.orig	2022-11-21 01:55:42 UTC
+++ Make.inc
@@ -251,7 +251,7 @@ docdir := $(prefix)/$(framework_documentation)
 libexecdir := $(prefix)/$(framework_helpers)
 datarootdir := $(prefix)/$(framework_resources)
 docdir := $(prefix)/$(framework_documentation)
-mandir := $(datarootdir)/man
+mandir := $(prefix)/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/$(framework_headers)
 sysconfdir := $(prefix)/$(framework_resources)
@@ -279,7 +279,7 @@ build_datarootdir := $(build_prefix)/share
 build_libdir := $(build_prefix)/lib
 build_libexecdir := $(build_prefix)/libexec
 build_datarootdir := $(build_prefix)/share
-build_mandir := $(build_datarootdir)/man
+build_mandir := $(build_prefix)/man
 build_man1dir := $(build_mandir)/man1
 build_includedir := $(build_prefix)/include
 build_sysconfdir := $(build_prefix)/etc
@@ -498,8 +498,8 @@ ifeq ($(USECLANG),1)
 endif
 
 ifeq ($(USECLANG),1)
-CC := $(CROSS_COMPILE)clang
-CXX := $(CROSS_COMPILE)clang++
+CC ?= $(CROSS_COMPILE)clang
+CXX ?= $(CROSS_COMPILE)clang++
 JCFLAGS := -std=gnu99 -pipe $(fPIC) -fno-strict-aliasing -D_FILE_OFFSET_BITS=64
 # AArch64 needs this flag to generate the .eh_frame used by libunwind
 JCPPFLAGS := -fasynchronous-unwind-tables
