# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest_game
PORTVERSION=	0.4.8
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Minetest game engine

LICENSE=	LGPL21

RUN_DEPENDS=	minetest:${PORTSDIR}/games/minetest

USE_GITHUB=	yes
GH_ACCOUNT=	minetest
GH_COMMIT=	51de423

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/minetest/games/${PORTNAME}
PORTDATA=	*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
