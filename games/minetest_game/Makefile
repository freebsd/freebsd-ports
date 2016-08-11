# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minetest_game
PORTVERSION=	0.4.14
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	The main game for the Minetest game engine

LICENSE=	LGPL21+

RUN_DEPENDS=	minetest:games/minetest

USE_GITHUB=	yes
GH_ACCOUNT=	minetest

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/minetest/games/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "game.conf menu mods" ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
