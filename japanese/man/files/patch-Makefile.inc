--- Makefile.inc.orig	Mon Apr  8 19:21:24 2002
+++ Makefile.inc	Mon Apr  8 19:22:12 2002
@@ -10,8 +10,8 @@
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
