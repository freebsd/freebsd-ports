--- Makefile.inc.bak	Wed Jul  4 17:40:24 2001
+++ Makefile.inc	Wed Jul  4 17:41:39 2001
@@ -10,8 +10,9 @@
 bindir=			${BINDIR}
 pager=			jless -s
 manpath_config_file=	/etc/manpath.config
-troff=			${bindir}/groff -S -mandoc
-nroff=                  ${bindir}/groff -S -Wall -Tnippon -mtty-char -mandoc
+troff=			${bindir}/groff -S -mandoc -dlang=ja_JP.eucJP
+nroff=                  ${bindir}/groff -S -Wall -Tnippon -mtty-char -mandoc\
+			-dlang=ja_JP.eucJP
 apropos=		${bindir}/japropos
 whatis=			${bindir}/jwhatis
 neqn=                   ${bindir}/geqn -Tascii
