# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdlroids
PORTVERSION=	1.3.4
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Enhanced shoot-the-asteroids game

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --datadir=${STAGEDIR}${PREFIX}/share
USE_GCC=	yes
USE_CSTD=	gnu89
USE_SDL=	mixer sdl

PORTDOCS=	ChangeLog README README.orig README.petopt README.xhyperoid TODO

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="SDLRoids" "" "${PORTNAME}" \
		"${PORTNAME} -n 2" "Game;ArcadeGame;" ""

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
