--- solenv/inc/unxfbsd.mk.orig	2019-09-17 22:55:21 UTC
+++ solenv/inc/unxfbsd.mk
@@ -173,7 +173,7 @@ LINKFLAGSRUNPATH_NONE=
 LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN'\'
 #LINKFLAGSRUNPATH_BOXT=-Wl,-z,origin -Wl,-rpath,\''$$ORIGIN/../../../basis-link/program'\'
 LINKFLAGSRUNPATH_NONE=
-LINKFLAGS=-Wl,-z,combreloc $(LDFLAGS) $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
+LINKFLAGS=-Wl,-z,combreloc -Wl,--undefined-version $(LDFLAGS) $(LINKFLAGSDEFS) $(LINKFLAGS_SYSBASE)
 
 # linker flags for linking applications
 LINKFLAGSAPPGUI= -Wl,-export-dynamic -Wl,--noinhibit-exec \
