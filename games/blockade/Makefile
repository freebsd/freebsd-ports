# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blockade
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	TUCOWS/x11/entertain \
		http://www.sourcefiles.org/Games/Arcade/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X version of the `blockade' Macintosh game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XORG=	x11

MAN6=		blockade.6
PLIST_FILES=	bin/blockade

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blockade ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/blockade.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
