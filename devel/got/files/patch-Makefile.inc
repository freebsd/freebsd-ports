--- Makefile.inc.orig	2020-11-26 12:53:05 UTC
+++ Makefile.inc
@@ -4,6 +4,13 @@ CPPFLAGS += -DGOT_LIBEXECDIR=${LIBEXECDIR} -DGOT_VERSI
 #CFLAGS += -DGOT_OBJ_CACHE_DEBUG
 #CFLAGS += -DGOT_DIFF_NO_MMAP
 
+OPENBSD_COMPAT := ${.PARSEDIR}/openbsd-compat
+CFLAGS += ${CPPFLAGS} -I${OPENBSD_COMPAT}
+CFLAGS += -Wno-pointer-sign
+
+LDFLAGS += -L${OPENBSD_COMPAT}
+LDADD += -lopenbsd-compat -lmd
+
 .if "${GOT_RELEASE}" == "Yes"
 PREFIX ?= /usr/local
 BINDIR ?= ${PREFIX}/bin
