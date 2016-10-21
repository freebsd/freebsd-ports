# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gemdropx
PORTVERSION=	0.9
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/gemdropx/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interesting one-player puzzle game for X (SDL)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake
USE_SDL=	image mixer sdl
ALL_TARGET=	${PORTNAME}

PORTDOCS=	AUTHORS.txt CHANGES.txt ICON.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Gem Drop X" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

post-patch:
	@${REINPLACE_CMD} \
	-e 's|sdl-config|${SDL_CONFIG}| ; \
	s|CC=gcc|CC?=${CC}| ; \
	s|CXX=gcc|CXX?=${CC}| ; \
	s|CFLAGS=-Wall ${SDL_CFLAGS}|CFLAGS+=-w ${SDL_CFLAGS}|' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKDIR} -name .xvpics | ${XARGS} ${RM} -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images sounds" \
		${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
