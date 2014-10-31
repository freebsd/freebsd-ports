# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	defendguin
PORTVERSION=	0.0.12
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/defendguin/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Your mission is to defend little penguinoids

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USE_SDL=	mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Defendguin" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	cd ${WRKSRC}/src && ${CC} ${CFLAGS} -DDATA_PREFIX=\"${DATADIR}/\" \
		`${SDL_CONFIG} --cflags` defendguin.c -o defendguin \
		`${SDL_CONFIG} --libs` -lSDL_mixer -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
