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
+CDEFS+=$(PTHREAD_CFLAGS) -D_PTHREADS -D_REENTRANT -DNEW_SOLAR -D_USE_NAMESPACE=1 -DSTLPORT_VERSION=450 -DHAVE_STL_INCLUDE_PATH
 
 # enable visibility define in "sal/types.h"
 .IF "$(HAVE_GCC_VISIBILITY_FEATURE)" == "TRUE"
@@ -88,7 +88,7 @@ CFLAGSENABLESYMBOLS=-g # was temporarily
 # flags for the C++ Compiler
 CFLAGSCC= -pipe $(ARCH_FLAGS) 
 # Flags for enabling exception handling
-CFLAGSEXCEPTIONS=-fexceptions -fno-enforce-eh-specs
+CFLAGSEXCEPTIONS=-fexceptions
 # Flags for disabling exception handling
 CFLAGS_NO_EXCEPTIONS=-fno-exceptions
 
@@ -156,7 +156,7 @@ LINKFLAGSRUNPATH_OXT=
 LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN'\'
 #LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
 LINKFLAGSRUNPATH_NONE=
-LINKFLAGS=-Wl,-z,combreloc  $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
+LINKFLAGS=-Wl,-z,combreloc $(LDFLAGS) $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec \
@@ -199,11 +199,11 @@ STDSHLCUIMT+=-ltcmalloc
 .ENDIF
 
 # libraries for linking applications
-STDLIBGUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed
-STDLIBCUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed
+STDLIBGUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed ${FBSD_LDFLAGS}
+STDLIBCUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed ${FBSD_LDFLAGS}
 # libraries for linking shared libraries
-STDSHLGUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed
-STDSHLCUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed
+STDSHLGUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed ${FBSD_LDFLAGS}
+STDSHLCUIMT+=-Wl,--as-needed $(PTHREAD_LIBS) -lm -Wl,--no-as-needed ${FBSD_LDFLAGS}
 
 X11LINK_DYNAMIC = -Wl,--as-needed -lXext -lX11 -Wl,--no-as-needed
 
