# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	default
PORTVERSION=	0.4.9.3
PORTREVISION=	2
CATEGORIES=	games
PKGNAMEPREFIX=	freeminer-
DIST_SUBDIR=	freeminer

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Freeminer game engine

LICENSE=	LGPL21

RUN_DEPENDS=	freeminer:${PORTSDIR}/games/freeminer

USE_GITHUB=	yes
GH_ACCOUNT=	freeminer
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	c2c50e8

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/freeminer/games/${PORTNAME}
PORTDATA=	*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
