# New ports collection makefile for:	bnetd
# Date created:		24 April 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	bnetd
PORTVERSION=	0.4.21
CATEGORIES=	games net
MASTER_SITES=	http://www.bnetd.org/files/

MAINTAINER=	ijliao@FreeBSD.org

MAN1=		bnchat.1 bnetd.1 bnftp.1 bnpass.1
MAN5=		bnetd.conf.5 bntext.5
MLINKS=		bntext.5 bnmotd.txt.5 bntext.5 bnnews.txt.5

do-configure:
	@(cd ${WRKSRC}/src; ${SETENV} CFLAGS="${CFLAGS}" \
	    ./configure --with-warn --with-bits --prefix=${PREFIX} ${CONFIGURE_TARGET})

do-build:
	@(cd ${WRKSRC}/src; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

do-install:
	cd ${WRKSRC}/bin; ${INSTALL_PROGRAM} * ${PREFIX}/bin
	cd ${WRKSRC}/sbin; ${INSTALL_PROGRAM} * ${PREFIX}/sbin
	cd ${WRKSRC}/man; ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1; ${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5
	${MKDIR} ${PREFIX}/bnetd; ${CP} -R ${WRKSRC}/files ${WRKSRC}/users ${WRKSRC}/conf ${WRKSRC}/reports ${PREFIX}/bnetd

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/bnetd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/bnetd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/bnetd.sh \
			${PREFIX}/etc/rc.d/bnetd.sh; \
	fi

.include <bsd.port.mk>
