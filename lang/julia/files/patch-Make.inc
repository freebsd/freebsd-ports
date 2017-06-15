--- Make.inc.orig	2016-09-20 02:54:21 UTC
+++ Make.inc
@@ -128,12 +128,7 @@ endif
 # disable automatic Makefile rules
 .SUFFIXES:
 
-# find out if git repository is available
-ifeq ($(shell [ -e $(JULIAHOME)/.git ] && echo true || echo "Warning: git information unavailable; versioning information limited" >&2), true)
-NO_GIT := 0
-else
 NO_GIT := 1
-endif
 
 # Julia's Semantic Versioning system labels the three decimal places in a version number as
 # the major, minor and patch versions.  Typically the major version would be incremented
@@ -178,7 +173,7 @@ libdir := $(prefix)/lib
 libexecdir := $(prefix)/libexec
 datarootdir := $(prefix)/share
 docdir := $(datarootdir)/doc/julia
-mandir := $(datarootdir)/man
+mandir := $(prefix)/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/include
 sysconfdir := $(prefix)/etc
@@ -192,7 +187,7 @@ build_libdir := $(build_prefix)/lib
 build_libexecdir := $(build_prefix)/libexec
 build_datarootdir := $(build_prefix)/share
 build_docdir := $(build_datarootdir)/doc/julia
-build_mandir := $(build_datarootdir)/man
+build_mandir := $(build_prefix)/man
 build_man1dir := $(build_mandir)/man1
 build_includedir := $(build_prefix)/include
 build_sysconfdir := $(build_prefix)/etc
@@ -340,7 +335,7 @@ endif
 ifeq ($(USEIFC), 1)
 FC := ifort
 else
-FC := $(CROSS_COMPILE)gfortran
+FC ?= $(CROSS_COMPILE)gfortran
 endif
 
 STDLIBCPP_FLAG :=
@@ -393,14 +388,14 @@ SHIPFLAGS := -O3 -ggdb2 -falign-function
 endif
 
 ifeq ($(USECLANG),1)
-CC := $(CROSS_COMPILE)clang
-CXX := $(CROSS_COMPILE)clang++
+CC ?= $(CROSS_COMPILE)clang
+CXX ?= $(CROSS_COMPILE)clang++
 JCFLAGS := -pipe $(fPIC) -fno-strict-aliasing -D_FILE_OFFSET_BITS=64
 # AArch64 needs this flag to generate the .eh_frame used by libunwind
 JCPPFLAGS := -fasynchronous-unwind-tables
 JCXXFLAGS := -pipe $(fPIC) -fno-rtti -pedantic
 DEBUGFLAGS := -O0 -g -DJL_DEBUG_BUILD -fstack-protector-all
-SHIPFLAGS := -O3 -g
+SHIPFLAGS := -O3
 ifeq ($(OS), Darwin)
 ifeq ($(USE_LIBCPP), 1)
 CC += -stdlib=libc++ -mmacosx-version-min=10.7
@@ -832,7 +827,7 @@ endif
 
 ifeq ($(USE_SYSTEM_UTF8PROC), 1)
   LIBUTF8PROC := -lutf8proc
-  UTF8PROC_INC := /usr/include
+  UTF8PROC_INC := $(LOCALBASE)/include
 else
   LIBUTF8PROC := $(build_libdir)/libutf8proc.a
   UTF8PROC_INC := $(build_includedir)
