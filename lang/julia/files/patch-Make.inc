--- Make.inc.orig	2023-08-24 16:20:21 UTC
+++ Make.inc
@@ -268,7 +268,7 @@ docdir := $(datarootdir)/doc/julia
 libexecdir := $(prefix)/libexec
 datarootdir := $(prefix)/share
 docdir := $(datarootdir)/doc/julia
-mandir := $(datarootdir)/man
+mandir := $(prefix)/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/include
 sysconfdir := $(prefix)/etc
@@ -286,7 +286,7 @@ build_datarootdir := $(build_prefix)/share
 build_libdir := $(build_prefix)/lib
 build_libexecdir := $(build_prefix)/libexec
 build_datarootdir := $(build_prefix)/share
-build_mandir := $(build_datarootdir)/man
+build_mandir := $(build_prefix)/man
 build_man1dir := $(build_mandir)/man1
 build_includedir := $(build_prefix)/include
 build_sysconfdir := $(build_prefix)/etc
@@ -654,33 +654,6 @@ endif
 include $(BUILDROOT)/$(MAKE_USER_FNAME)
 endif
 
-# A bit of a kludge to work around libraries linking to FreeBSD's outdated system libgcc_s
-# Instead, let's link to the libgcc_s corresponding to the installation of gfortran
-ifeq ($(OS),FreeBSD)
-ifneq (,$(findstring gfortran,$(FC)))
-
-# First let's figure out what version of GCC we're dealing with
-_GCCMAJOR := $(shell $(FC) -dumpversion 2>/dev/null | cut -d'.' -f1)
-_GCCMINOR := $(shell $(FC) -dumpversion 2>/dev/null | cut -d'.' -f2)
-
-# The ports system uses major and minor for GCC < 5 (e.g. gcc49 for GCC 4.9), otherwise major only
-ifeq ($(_GCCMAJOR),4)
-  _GCCVER := $(_GCCMAJOR)$(_GCCMINOR)
-else
-  _GCCVER := $(_GCCMAJOR)
-endif
-
-# Allow the user to specify this in Make.user
-GCCPATH ?= $(LOCALBASE)/lib/gcc$(_GCCVER)
-
-# We're going to copy over the libraries we need from GCCPATH into build_libdir, then
-# tell everyone to look for them there. At install time, the build_libdir added into
-# the RPATH here is removed by patchelf.
-LDFLAGS += -L$(build_libdir) -Wl,-rpath,$(build_libdir)
-
-endif # gfortran
-endif # FreeBSD
-
 ifneq ($(CC_BASE)$(CXX_BASE),$(shell echo $(CC) | cut -d' ' -f1)$(shell echo $(CXX) | cut -d' ' -f1))
     $(error Forgot override directive on CC or CXX in Make.user? Cowardly refusing to build)
 endif
@@ -1295,14 +1268,8 @@ JLDFLAGS += -Wl,-Bdynamic
 
 ifeq ($(OS), FreeBSD)
 JLDFLAGS += -Wl,-Bdynamic
-OSLIBS += -lelf -lkvm -lrt -lpthread -latomic
+OSLIBS += -lelf -lkvm -lrt -lpthread
 
-# Tweak order of libgcc_s in DT_NEEDED,
-# make it loaded first to
-# prevent from linking to outdated system libs.
-# See #21788
-OSLIBS += -lgcc_s
-
 OSLIBS += -Wl,--export-dynamic -Wl,--version-script=$(JULIAHOME)/src/julia.expmap \
 	$(NO_WHOLE_ARCHIVE)
 endif
@@ -1511,30 +1478,6 @@ LIBJULIACODEGEN_DEBUG_INSTALL_DEPLIB := $(call dep_lib
 LIBJULIACODEGEN_DEBUG_BUILD_DEPLIB := $(call dep_lib_path,$(build_libdir),$(build_shlibdir)/libjulia-codegen-debug.$(JL_MAJOR_SHLIB_EXT))
 LIBJULIACODEGEN_DEBUG_INSTALL_DEPLIB := $(call dep_lib_path,$(libdir),$(private_shlibdir)/libjulia-codegen-debug.$(JL_MAJOR_SHLIB_EXT))
 
-ifeq ($(OS),WINNT)
-ifeq ($(BINARY),32)
-LIBGCC_NAME := libgcc_s_sjlj-1.$(SHLIB_EXT)
-else
-LIBGCC_NAME := libgcc_s_seh-1.$(SHLIB_EXT)
-endif
-endif
-# On macOS, libgcc_s has soversion 1.1 always on aarch64 and only for GCC 12+
-# (-> libgfortran 5) on x86_64
-ifeq ($(OS),Darwin)
-ifeq ($(ARCH),aarch64)
-LIBGCC_NAME := libgcc_s.1.1.$(SHLIB_EXT)
-else
-ifeq ($(LIBGFORTRAN_VERSION),5)
-LIBGCC_NAME := libgcc_s.1.1.$(SHLIB_EXT)
-else
-LIBGCC_NAME := libgcc_s.1.$(SHLIB_EXT)
-endif
-endif
-endif
-ifneq ($(findstring $(OS),Linux FreeBSD),)
-LIBGCC_NAME := libgcc_s.$(SHLIB_EXT).1
-endif
-
 # USE_SYSTEM_CSL causes it to get symlinked into build_private_shlibdir
 ifeq ($(USE_SYSTEM_CSL),1)
 LIBGCC_BUILD_DEPLIB := $(call dep_lib_path,$(build_libdir),$(build_private_shlibdir)/$(LIBGCC_NAME))
@@ -1567,7 +1510,6 @@ LIBM_INSTALL_DEPLIB := $(call dep_lib_path,$(libdir),$
 LIBM_INSTALL_DEPLIB := $(call dep_lib_path,$(libdir),$(private_shlibdir)/$(LIBMNAME).$(SHLIB_EXT))
 
 # We list:
-#  * libgcc_s, because FreeBSD needs to load ours, not the system one.
 #  * libopenlibm, because Windows has an untrustworthy libm, and we want to use ours more than theirs
 #  * libstdc++, because while performing `libstdc++` probing we need to
 #    know the path to the bundled `libstdc++` library.
@@ -1589,7 +1531,6 @@ LOADER_BUILD_DEP_LIBS = $(call build_deplibs, \
 endef
 
 LOADER_BUILD_DEP_LIBS = $(call build_deplibs, \
-    $(LIBGCC_BUILD_DEPLIB) \
     $(LIBM_BUILD_DEPLIB) \
     @$(LIBSTDCXX_BUILD_DEPLIB) \
     @$(LIBJULIAINTERNAL_BUILD_DEPLIB) \
@@ -1597,7 +1538,6 @@ LOADER_DEBUG_BUILD_DEP_LIBS = $(call build_deplibs, \
 )
 
 LOADER_DEBUG_BUILD_DEP_LIBS = $(call build_deplibs, \
-   $(LIBGCC_BUILD_DEPLIB) \
    $(LIBM_BUILD_DEPLIB) \
    @$(LIBSTDCXX_BUILD_DEPLIB) \
    @$(LIBJULIAINTERNAL_DEBUG_BUILD_DEPLIB) \
@@ -1605,14 +1545,12 @@ LOADER_INSTALL_DEP_LIBS = $(call build_deplibs, \
 )
 
 LOADER_INSTALL_DEP_LIBS = $(call build_deplibs, \
-    $(LIBGCC_INSTALL_DEPLIB) \
     $(LIBM_INSTALL_DEPLIB) \
     @$(LIBSTDCXX_INSTALL_DEPLIB) \
     @$(LIBJULIAINTERNAL_INSTALL_DEPLIB) \
     @$(LIBJULIACODEGEN_INSTALL_DEPLIB) \
 )
 LOADER_DEBUG_INSTALL_DEP_LIBS = $(call build_deplibs, \
-    $(LIBGCC_INSTALL_DEPLIB) \
     $(LIBM_INSTALL_DEPLIB) \
     @$(LIBSTDCXX_INSTALL_DEPLIB) \
     @$(LIBJULIAINTERNAL_DEBUG_INSTALL_DEPLIB) \
