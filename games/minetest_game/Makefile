# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest_game
PORTVERSION=	0.4.4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Minetest game engine

LICENSE=	LGPL21

RUN_DEPENDS=	minetest:${PORTSDIR}/games/minetest

USE_GITHUB=	yes
GH_ACCOUNT=	celeron55
GH_TAGNAME=	0.4.4
GH_COMMIT=	3928ecc

NO_BUILD=	yes
DATADIR=	${PREFIX}/share/minetest/games/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} '*' ${DATADIR}/

.include <bsd.port.mk>
