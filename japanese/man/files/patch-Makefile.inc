--- Makefile.inc.orig	2001-01-15 09:41:22 UTC
+++ Makefile.inc
@@ -3,15 +3,15 @@ BINDIR=			${PREFIX}/bin
 # pick up a user's own version of some utility and hose ourselves.
 #
 BINDIR=			${PREFIX}/bin
-MANDIR=			${PREFIX}/man/ja/man
-EMANDIR=		${PREFIX}/man/man
+MANDIR=			${PREFIX}/share/man/ja/man
+EMANDIR=		${PREFIX}/share/man/man
 libdir=			${PREFIX}/etc
 libexecdir=		${PREFIX}/libexec
 bindir=			${BINDIR}
 pager=			jless -s
 manpath_config_file=	/etc/manpath.config
-troff=			${bindir}/groff -S -mandoc
-nroff=                  ${bindir}/groff -S -Wall -Tnippon -mtty-char -mandoc
+troff=			${bindir}/groff -S -man -dlang=ja_JP.eucJP
+nroff=                  ${bindir}/groff -S -Wall -Tnippon -mtty-char -man -dlang=ja_JP.eucJP
 apropos=		${bindir}/japropos
 whatis=			${bindir}/jwhatis
 neqn=                   ${bindir}/geqn -Tascii
