--- Make.inc.orig	2026-10-25 17:06:47 UTC
+++ Make.inc
@@ -315,7 +315,7 @@ docdir := $(datarootdir)/doc/julia
 libexecdir := $(prefix)/libexec
 datarootdir := $(prefix)/share
 docdir := $(datarootdir)/doc/julia
-mandir := $(datarootdir)/man
+mandir := $(prefix)/share/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/include
 sysconfdir := $(prefix)/etc
@@ -1386,7 +1386,7 @@ ifeq ($(USE_SYSTEM_LIBUV), 1)
 endif
 
 ifeq ($(USE_SYSTEM_LIBUV), 1)
-  LIBUV := $(LOCALBASE)/lib/libuv-julia.a
+  LIBUV := $(LOCALBASE)/lib/libuv.a
   LIBUV_INC := $(LOCALBASE)/include
 else
   LIBUV := $(build_libdir)/libuv.a
@@ -1609,7 +1609,7 @@ ifeq ($(OS), FreeBSD)
 endif
 
 ifeq ($(OS), FreeBSD)
-JLDFLAGS += -Wl,-Bdynamic
+JLDFLAGS += -Wl,-Bdynamic -Wl,-L$(GCCPATH)
 OSLIBS += -lelf -lkvm -lrt -lpthread -latomic
 
 # Tweak order of libgcc_s in DT_NEEDED,
