# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	syobon
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://download.zapek.com/software/${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform game as Super Mario Bros

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake pkgconfig
DOS2UNIX_FILES=	*.cpp *.txt
USE_SDL=	sdl gfx image mixer ttf
USE_GCC=	yes
ALL_TARGET=	${PORTNAME}

MAKE_ENV=	GAMEDATA="${DATADIR}"

PORTDOCS=	README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Syobon Action" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in BGM SE res
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
