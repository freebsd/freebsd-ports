--- Make.inc.orig	2021-12-23 01:12:50 UTC
+++ Make.inc
@@ -243,7 +243,7 @@ libdir := $(prefix)/$(framework_currver)
 libexecdir := $(prefix)/$(framework_helpers)
 datarootdir := $(prefix)/$(framework_resources)
 docdir := $(prefix)/$(framework_documentation)
-mandir := $(datarootdir)/man
+mandir := $(prefix)/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/$(framework_headers)
 sysconfdir := $(prefix)/$(framework_resources)
@@ -271,7 +271,7 @@ build_depsbindir := $(build_prefix)/tools
 build_libdir := $(build_prefix)/lib
 build_libexecdir := $(build_prefix)/libexec
 build_datarootdir := $(build_prefix)/share
-build_mandir := $(build_datarootdir)/man
+build_mandir := $(build_prefix)/man
 build_man1dir := $(build_mandir)/man1
 build_includedir := $(build_prefix)/include
 build_sysconfdir := $(build_prefix)/etc
@@ -510,8 +510,8 @@ SHIPFLAGS := -O3 -ggdb2 -falign-functions
 endif
 
 ifeq ($(USECLANG),1)
-CC := $(CROSS_COMPILE)clang
-CXX := $(CROSS_COMPILE)clang++
+CC ?= $(CROSS_COMPILE)clang
+CXX ?= $(CROSS_COMPILE)clang++
 JCFLAGS := -std=gnu99 -pipe $(fPIC) -fno-strict-aliasing -D_FILE_OFFSET_BITS=64
 # AArch64 needs this flag to generate the .eh_frame used by libunwind
 JCPPFLAGS := -fasynchronous-unwind-tables
