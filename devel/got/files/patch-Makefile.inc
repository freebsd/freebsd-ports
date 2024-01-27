--- Makefile.inc.orig	2023-09-03 23:15:32 UTC
+++ Makefile.inc
@@ -6,11 +6,24 @@ CPPFLAGS += -DGOT_LIBEXECDIR=${LIBEXECDIR} -DGOT_VERSI
 #CFLAGS += -DGOT_DELTA_CACHE_DEBUG
 #CFLAGS += -DGOT_DIFF_NO_MMAP
 
+# work around https://gcc.gnu.org/bugzilla/show_bug.cgi?id=63567
+.include <bsd.compiler.mk>
+.if ${COMPILER_TYPE} == "gcc" && ${COMPILER_VERSION} < 50000
+CSTD = gnu89
+.endif
+
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
 LIBEXECDIR ?= ${PREFIX}/libexec
-MANDIR ?= ${PREFIX}/man/man
+MANDIR ?= ${PREFIX}/share/man/man
 .else
 CFLAGS += -Werror -Wall -Wstrict-prototypes -Wmissing-prototypes
 CFLAGS += -Wwrite-strings -Wunused-variable
