# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bugsquish
PORTVERSION=	0.0.6
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/bugsquish/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:music
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_music${EXTRACT_SUFX}:music

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Action game not unlike light gun arcade games

LICENSE=	GPLv2

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USES=		gmake
USE_SDL=	image mixer sdl

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Bug Squish" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
	${TAR} xfjp ${_DISTDIR}/${PORTNAME}_music${EXTRACT_SUFX} -C \
		${WRKSRC}/data/music/
	@cd ${WRKSRC}/data/music ; ${RM} -f *.mod
	@${FIND} ${WRKDIR} -name .xvpics | ${XARGS} ${RM} -fr

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

.  for d in embedded images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.  endfor

	${LN} -sf ${PREFIX}/share/bugsquish/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
