--- ./solenv/inc/unxgcc.mk.orig	2013-01-16 04:41:51.000000000 -0500
+++ ./solenv/inc/unxgcc.mk	2013-02-12 20:50:31.000000000 -0500
@@ -191,11 +191,11 @@
 # entry. This will cause both, DT_RPATH and DT_RUNPATH entries, to be created
 #
 LINKFLAGSDEFS*=-Wl,-z,defs
-LINKFLAGSRUNPATH_URELIB=-Wl,-rpath,\''$$ORIGIN'\',--enable-new-dtags
-LINKFLAGSRUNPATH_UREBIN=-Wl,-rpath,\''$$ORIGIN/../lib:$$ORIGIN'\',--enable-new-dtags
+LINKFLAGSRUNPATH_URELIB=-Wl,-z,origin,-rpath,\''$$ORIGIN'\',--enable-new-dtags
+LINKFLAGSRUNPATH_UREBIN=-Wl,-z,origin,-rpath,\''$$ORIGIN/../lib:$$ORIGIN'\',--enable-new-dtags
     #TODO: drop $ORIGIN once no URE executable is also shipped in OOo
-LINKFLAGSRUNPATH_OOO=-Wl,-rpath,\''$$ORIGIN:$$ORIGIN/../ure-link/lib'\',--enable-new-dtags
-LINKFLAGSRUNPATH_SDKBIN=-Wl,-rpath,\''$$ORIGIN/../../ure-link/lib'\',--enable-new-dtags
+LINKFLAGSRUNPATH_OOO=-Wl,-z,origin,-rpath,\''$$ORIGIN:$$ORIGIN/../ure-link/lib'\',--enable-new-dtags
+LINKFLAGSRUNPATH_SDKBIN=-Wl,-z,origin,-rpath,\''$$ORIGIN/../../ure-link/lib'\',--enable-new-dtags
 LINKFLAGSRUNPATH_OXT=
 LINKFLAGSRUNPATH_NONE=
 # flag -Wl,-z,noexecstack sets the NX bit on the stack
