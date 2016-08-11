# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blockade
DISTVERSION=	1_00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.sourcefiles.org/Games/Arcade/
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X version of the `blockade' Macintosh game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11

PLIST_FILES=	bin/blockade man/man6/blockade.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blockade ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blockade.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
