--- libexec/Makefile.inc.orig	2020-09-10 19:02:02 UTC
+++ libexec/Makefile.inc
@@ -1,7 +1,5 @@
 .include "../Makefile.inc"
 
-realinstall:
-	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} \
-	-m ${BINMODE} ${PROG} ${LIBEXECDIR}/${PROG}
+BINDIR = ${PREFIX}/libexec
 
-NOMAN = Yes
+MAN =
