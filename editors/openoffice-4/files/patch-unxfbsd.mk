--- solenv/inc/unxfbsd.mk~	2012-10-31 10:39:44.000000000 +0900
+++ solenv/inc/unxfbsd.mk	2012-10-31 17:42:59.000000000 +0900
@@ -80,14 +80,14 @@
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
@@ -145,7 +145,7 @@
 LINKFLAGSRUNPATH_OXT=
 LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
 LINKFLAGSRUNPATH_NONE=
-LINKFLAGS=-Wl,-z,combreloc  $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
+LINKFLAGS=-Wl,-z,combreloc %%RPATH%% $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec \
