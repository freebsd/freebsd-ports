--- Makefile.inc.orig	2020-07-25 09:10:27 UTC
+++ Makefile.inc
@@ -3,6 +3,13 @@ CPPFLAGS += -DGOT_LIBEXECDIR=${LIBEXECDIR} -DGOT_VERSI
 #CFLAGS += -DGOT_NO_OBJ_CACHE
 #CFLAGS += -DGOT_OBJ_CACHE_DEBUG
 
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
