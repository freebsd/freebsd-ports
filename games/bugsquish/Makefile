# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bugsquish
PORTVERSION=	0.0.6
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/bugsquish/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:music
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_music${EXTRACT_SUFX}:music

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action game not unlike light gun arcade games

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		gmake
USE_SDL=	image mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt

DESKTOP_ENTRIES="Bug Squish" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-extract:
	${TAR} xfjp ${_DISTDIR}/${PORTNAME}_music${EXTRACT_SUFX} -C \
		${WRKSRC}/data/music/
	@cd ${WRKSRC}/data/music ; ${RM} *.mod
	@${FIND} ${WRKDIR} -name .xvpics -print0 | ${XARGS} -0 ${RM} -r

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/bugsquish/|${DATADIR}/| ; \
		s|CFLAGS=-Wall -O2|CFLAGS+=| ; \
		s|SDL_CFLAGS :=|SDL_CFLAGS+=| ; \
		s|SDL_LDFLAGS :=|SDL_LDFLAGS+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|corpses.mod|corpses.ogg| ; \
		s|adventures.mod|adventures.ogg|' \
		${WRKSRC}/bugsquish.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "embedded images music sounds" ${STAGEDIR}${DATADIR})
	${LN} -sf ${PREFIX}/share/bugsquish/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
