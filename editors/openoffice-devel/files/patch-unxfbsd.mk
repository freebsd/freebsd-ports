--- solenv/inc/unxfbsd.mk.orig	2014-09-19 18:16:56 UTC
+++ solenv/inc/unxfbsd.mk
@@ -27,7 +27,7 @@ ASM=
 AFLAGS=
 
 SOLAR_JAVA*=
-PICSWITCH*:=-fpic
+PICSWITCH*:=-fPIC
 JAVAFLAGSDEBUG=-g
 
 # Include arch specific makefile.
@@ -49,7 +49,7 @@ JAVAFLAGSDEBUG=-g
 #LINKOUTPUT_FILTER=" |& $(SOLARENV)/bin/msg_filter"
 
 # _PTHREADS is needed for the stl
-CDEFS+=$(PTHREAD_CFLAGS) -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=450
+CDEFS+=$(PTHREAD_CFLAGS) -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 %%HAVE_STL_INCLUDE_PATH%%
 
 # enable visibility define in "sal/types.h"
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
@@ -86,14 +86,14 @@ CFLAGSENABLESYMBOLS=-g # was temporarily
 .ENDIF
 
 # flags for the C++ Compiler
-CFLAGSCC= -pipe $(ARCH_FLAGS) 
+CFLAGSCC= -pipe $(ARCH_FLAGS) %%RPATH%%
 # Flags for enabling exception handling
-CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
+CFLAGSEXCEPTIONS=-fexceptions
 # Flags for disabling exception handling
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
 # -fpermissive should be removed as soon as possible
-CFLAGSCXX= -pipe $(ARCH_FLAGS) 
+CFLAGSCXX= -pipe $(ARCH_FLAGS) %%RPATH%%
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
 CFLAGSCXX += -fvisibility-inlines-hidden
 .ENDIF # "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
@@ -156,7 +156,7 @@ LINKFLAGSRUNPATH_OXT=
 LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN'\'
 #LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
 LINKFLAGSRUNPATH_NONE=
-LINKFLAGS=-Wl,-z,combreloc  $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
+LINKFLAGS=-Wl,-z,combreloc %%RPATH%% $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec \
