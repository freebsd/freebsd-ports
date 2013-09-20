# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	defendguin
PORTVERSION=	0.0.12
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/defendguin/src/ \
		ftp://ftp.billsgames.com/unix/x/defendguin/src/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Your mission is to defend little penguinoids

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_SDL=	mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

MAN6=		${PORTNAME}.6

DESKTOP_ENTRIES="Defendguin" "${COMMENT}"  \
		"share/pixmaps/${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false


NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DDATA_PREFIX=\"${DATADIR}/\" \
		`${SDL_CONFIG} --cflags` defendguin.c -o defendguin \
		`${SDL_CONFIG} --libs` -lSDL_mixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@(cd ${WRKSRC}/../data && ${COPYTREE_SHARE} "images music sounds" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${MAN6:S|^|${WRKSRC}/|} ${MAN6PREFIX}/man/man6/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../docs/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
