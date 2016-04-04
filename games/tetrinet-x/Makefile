# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	tetrinet-x
PORTVERSION=	1.13.16
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/ \
		ftp://ftp.dementia.nu/tetrinet/servers/tetrix/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gmarco@gufi.org
COMMENT=	Addictive 6 player tetr*s game

WRKSRC=		${WRKDIR}/tetrinetx-${PORTVERSION}
SUB_FILES=	pkg-message
USE_RC_SUBR=	tetrinetx

do-build:
	(cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} main.c -o ../bin/tetrix.freebsd)
	(cd ${WRKSRC}/contrib/query/src && \
		${CC} ${CFLAGS} query.c -o ../../../bin/server-query)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tetrix.freebsd ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/server-query ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.conf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.log ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.secure ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/game.winlist ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/tetrinetx ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
