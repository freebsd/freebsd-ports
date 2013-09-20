# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bugsquish
PORTVERSION=	0.0.6
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/bugsquish/src/ \
		ftp://ftp.billsgames.com/unix/x/bugsquish/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Action game not unlike light gun arcade games

LICENSE=	GPLv2

USE_SDL=	image mixer sdl
USE_GMAKE=	yes

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

DESKTOP_ENTRIES="Bug Squish" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/bugsquish/|${DATADIR}/|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=-Wall -O2|CFLAGS+=|' \
	-e 's|SDL_CFLAGS :=|SDL_CFLAGS+=|' \
	-e 's|SDL_LDFLAGS :=|SDL_LDFLAGS+=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.  for d in embedded images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor

	${LN} -sf ${PREFIX}/share/bugsquish/embedded/images/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
