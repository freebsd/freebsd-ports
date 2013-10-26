# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	syobon
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://download.zapek.com/software/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${DISTVERSION}_src${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Platform game as Super Mario Bros

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake pkgconfig
USE_SDL=	sdl gfx image mixer ttf
USE_DOS2UNIX=	*.cpp *.txt
USE_GCC=	yes
ALL_TARGET=	${PORTNAME}

MAKE_ENV=	GAMEDATA="${DATADIR}"

PORTDOCS=	README.txt

DESKTOP_ENTRIES="Syobon Action" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "BGM SE res" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
