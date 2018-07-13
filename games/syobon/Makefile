# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syobon
PORTVERSION=	1.0.1
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://zapek.com/wp-content/uploads/2010/09/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}

LICENSE=	NONE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform game as Super Mario Bros

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake pkgconfig
DOS2UNIX_FILES=	*.cpp *.txt
USE_SDL=	sdl gfx image mixer ttf
USE_GCC=	yes
ALL_TARGET=	${PORTNAME}

MAKE_ENV=	GAMEDATA="${DATADIR}"

PORTDOCS=	README.txt

DESKTOP_ENTRIES="Syobon Action" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGM SE res" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
