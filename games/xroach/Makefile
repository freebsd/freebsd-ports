# Created by: markm
# $FreeBSD$

PORTNAME=	xroach
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cockroaches hide under your windows

USE_XORG=	x11
PLIST_FILES=	bin/xroach man/man6/xroach.6.gz

IGNOREFILES=	${DISTFILES}
WRKSRC=		${WRKDIR}/pub/bsd-sources/4.4BSD-Lite/usr/src/games/xroach

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/xroach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xroach.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
