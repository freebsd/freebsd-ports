
Apply the patch and add file given below

diff -ur fmio.old/Makefile fmio/Makefile
--- fmio.old/Makefile	Mon Mar 18 20:56:28 2002
+++ fmio/Makefile	Wed Apr 24 00:15:23 2002
@@ -6,7 +6,7 @@
 #
 
 PORTNAME=	fmio
-PORTVERSION=	1.2.18
+PORTVERSION=	1.2.25
 CATEGORIES=	audio
 MASTER_SITES=	http://www.jumbo.narod.ru/src/fmio/
 
@@ -16,10 +16,33 @@
 MANCOMPRESSED=	no
 
 pre-build:
-	${PERL} -pi.orig -e "s@lib fmio man@lib fmio@g; \
-			     s@install -c -o root@#install@g" ${WRKSRC}/Makefile
+.if !defined(WITH_XTREME)
+	@${ECHO_MSG}
+	@${ECHO_MSG} "If you want to compile with Highway Xtreme support,"
+	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_XTREME=yes\""
+	@${ECHO_MSG}
+.endif
 
-post-install:
+post-build:
+.if defined(WITH_XTREME)
+	@${MAKE} ${WRKSRC}/utils/bktrctl
+.endif
+
+do-install:
+.if defined(WITH_XTREME)
+	${INSTALL} ${WRKSRC}/utils/bktrctl ${PREFIX}/bin
+	${INSTALL} files/bktrctl.sh ${PREFIX}/etc/rc.d
+.endif
+	${INSTALL} -m 4555 ${WRKSRC}/fmio ${PREFIX}/bin
 	${INSTALL_MAN} ${WRKSRC}/fmio.1 ${MANPREFIX}/man/man1
+
+
+
+post-install:
+.if !defined(WITH_XTREME)
+	${GREP} -v "bktrctl.sh" ${TMPPLIST} > ${TMPPLIST}.tmp
+	${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
+.endif
+
 
 .include <bsd.port.mk>
diff -ur fmio.old/distinfo fmio/distinfo
--- fmio.old/distinfo	Mon Mar 18 20:56:28 2002
+++ fmio/distinfo	Tue Apr 23 14:55:43 2002
@@ -1 +1 @@
-MD5 (fmio-1.2.18.tar.gz) = 3260dfb3e9ae3a7baa9912bf26ec1d43
+MD5 (fmio-1.2.25.tar.gz) = 4dacdd09098e83866b9309d4d9abf289
diff -ur fmio.old/pkg-plist fmio/pkg-plist
--- fmio.old/pkg-plist	Sat Apr  7 04:33:50 2001
+++ fmio/pkg-plist	Tue Apr 23 23:25:01 2002
@@ -1 +1,2 @@
 bin/fmio
+etc/rc.d/bktrctl.sh


-------------- files/bktrctl.sh ---------------------------

#!/bin/sh


if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi


case "$1" in
start)
	bktrctl 2>/dev/null >/dev/null && echo -n " bktrctl"
	;;
stop)
	killall bktrctl && echo -n " bktrctl"
	;;
*)
	echo "Usage: `basename $0` {start|stop}" >&2
	exit 64
	;;
esac

exit 0
