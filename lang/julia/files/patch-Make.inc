--- Make.inc.orig	2024-04-30 17:45:14 UTC
+++ Make.inc
@@ -260,7 +260,7 @@ docdir := $(datarootdir)/doc/julia
 libexecdir := $(prefix)/libexec
 datarootdir := $(prefix)/share
 docdir := $(datarootdir)/doc/julia
-mandir := $(datarootdir)/man
+mandir := $(prefix)/share/man
 man1dir := $(mandir)/man1
 includedir := $(prefix)/include
 sysconfdir := $(prefix)/etc
@@ -1339,7 +1339,7 @@ ifeq ($(OS), FreeBSD)
 endif
 
 ifeq ($(OS), FreeBSD)
-JLDFLAGS += -Wl,-Bdynamic
+JLDFLAGS += -Wl,-Bdynamic -Wl,-L$(GCCPATH)
 OSLIBS += -lelf -lkvm -lrt -lpthread -latomic
 
 # Tweak order of libgcc_s in DT_NEEDED,
@@ -1348,8 +1348,7 @@ OSLIBS += -lgcc_s
 # See #21788
 OSLIBS += -lgcc_s
 
-OSLIBS += -Wl,--export-dynamic -Wl,--version-script=$(BUILDROOT)/src/julia.expmap \
-	$(NO_WHOLE_ARCHIVE)
+OSLIBS += -Wl,--export-dynamic $(NO_WHOLE_ARCHIVE)
 endif
 
 ifeq ($(OS), Darwin)
