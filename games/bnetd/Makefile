# New ports collection makefile for:	bnetd
# Version required:	0.4.19
# Date created:		24 April 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	bnetd-0.4.19
CATEGORIES=	games net
MASTER_SITES=	http://www.bnetd.org/files/

MAINTAINER=	ijliao@csie.nctu.edu.tw

MAN1=		bnchat.1 bnetd.1 bnftp.1 bnpass.1
MAN4=		bnetd.conf.4 bntext.4
MLINKS=		bntext.4 bnmotd.txt.4 bntext.4 bnnews.txt.4

do-configure:
	@(cd ${WRKSRC}/src; ${SETENV} CFLAGS="${CFLAGS}" \
	    ./configure --prefix=${PREFIX} ${CONFIGURE_TARGET})

do-build:
	@(cd ${WRKSRC}/src; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

do-install:
	cd ${WRKSRC}/bin; ${INSTALL_PROGRAM} * ${PREFIX}/bin
	cd ${WRKSRC}/sbin; ${INSTALL_PROGRAM} * ${PREFIX}/sbin
	cd ${WRKSRC}/man; ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1; ${INSTALL_MAN} ${MAN4} ${MAN4PREFIX}/man/man4
	${MKDIR} ${PREFIX}/bnetd; ${CP} -R ${WRKSRC}/files ${WRKSRC}/users ${WRKSRC}/conf ${WRKSRC}/reports ${PREFIX}/bnetd

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/bnetd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/bnetd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/bnetd.sh; \
		${ECHO} "cd ${PREFIX}; [ -x sbin/bnetd -a -f bnetd/conf/bnetd.conf ] && sbin/bnetd -c bnetd/conf/bnetd.conf > /dev/null && ${ECHO} -n ' bnetd'" >> ${PREFIX}/etc/rc.d/bnetd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/bnetd.sh; \
	fi

.include <bsd.port.mk>
