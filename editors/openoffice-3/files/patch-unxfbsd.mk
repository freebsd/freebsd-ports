--- solenv/inc/unxfbsd.mk.orig	2011-12-21 09:47:20.000000000 +0900
+++ solenv/inc/unxfbsd.mk	2011-12-25 20:48:29.000000000 +0900
@@ -84,14 +84,14 @@
 .ENDIF
 
 # flags for the C++ Compiler
-CFLAGSCC= -pipe $(ARCH_FLAGS)
+CFLAGSCC= -pipe $(ARCH_FLAGS) %%RPATH%%
 # Flags for enabling exception handling
 CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
 # Flags for disabling exception handling
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
 # -fpermissive should be removed as soon as possible
-CFLAGSCXX= -pipe $(ARCH_FLAGS)
+CFLAGSCXX= -pipe $(ARCH_FLAGS) %%RPATH%%
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 CFLAGSCXX += -fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
@@ -140,16 +140,16 @@
 LINKFLAGS_SYSBASE:=-Wl,--sysroot=$(SYSBASE)
 .ENDIF          # "$(SYSBASE)"!=""
 LINKFLAGSDEFS*=-Wl,-z,defs
-LINKFLAGSRUNPATH_URELIB=-Wl,-rpath,\''$$ORIGIN'\'
-LINKFLAGSRUNPATH_UREBIN=-Wl,-rpath,\''$$ORIGIN/../lib:$$ORIGIN'\'
+LINKFLAGSRUNPATH_URELIB=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN'\'
+LINKFLAGSRUNPATH_UREBIN=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../lib:$$ORIGIN'\'
     #TODO: drop $ORIGIN once no URE executable is also shipped in OOo
-LINKFLAGSRUNPATH_OOO=-Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../ure-link/lib'\'
-LINKFLAGSRUNPATH_SDK=-Wl,-rpath,\''$$ORIGIN/../../ure-link/lib'\'
-LINKFLAGSRUNPATH_BRAND=-Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../basis-link/program:$$ORIGIN/../basis-link/ure-link/lib'\'
+LINKFLAGSRUNPATH_OOO=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../ure-link/lib'\'
+LINKFLAGSRUNPATH_SDK=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../ure-link/lib'\'
+LINKFLAGSRUNPATH_BRAND=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../basis-link/program:$$ORIGIN/../basis-link/ure-link/lib'\'
 LINKFLAGSRUNPATH_OXT=
-LINKFLAGSRUNPATH_BOXT=-Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
+LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
 LINKFLAGSRUNPATH_NONE=
-LINKFLAGS=-Wl,-z,combreloc $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
+LINKFLAGS=-Wl,-z,combreloc %%RPATH%% $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec \
