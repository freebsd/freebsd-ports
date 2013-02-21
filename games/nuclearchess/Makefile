# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	nuclearchess
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/nuclearchess/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Chess variant designed to be short and fun for all players

LICENSE=	GPLv2

BUILD_DEPENDS=	pamscale:${PORTSDIR}/graphics/netpbm

USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DATADIR}
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog

DESKTOP_ENTRIES="NuclearChess" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-build:
	@(cd ${WRKSRC}/gfx && \
		${LOCALBASE}/bin/pngtopnm atom.png | \
		${LOCALBASE}/bin/pamscale .22 | ${LOCALBASE}/bin/pnmtopng > nuclearchess.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/gfx/nuclearchess.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
