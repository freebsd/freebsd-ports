# $FreeBSD$

PORTNAME=	sdl_lopan
PORTVERSION=	10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.linuxmotors.com/sdllopan/downloads/ \
		http://www.linuxmotors.com/sdllopan/:icons
DISTFILES=	sdllopan-${DISTVERSION}.tgz \
		sdllopan.gif:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	sdllopan-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Mahjong game remake

LICENSE=	GPLv2

BUILD_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/sdllopan-${PORTVERSION}

USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

ALL_TARGET=

PLIST_FILES=	bin/sdllopan \
		share/pixmaps/sdllopan.png

PORTDATA=	*
PORTDOCS=	Changelog README

DESKTOP_ENTRIES="SDL Lopan" "${COMMENT}" "sdllopan" \
		"sdllopan" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|data/bg%d.pcx|${DATADIR}/data/bg%d.pcx|' \
	-e 's|data/tiles%d.pcx|${DATADIR}/data/tiles%d.pcx|' \
	-e 's|char temp\[64\];|char temp\[256\];|' \
		${WRKSRC}/lopan.c

post-build:
	@(cd ${WRKSRC} && \
		${LOCALBASE}/bin/giftopnm ${DISTDIR}/${DIST_SUBDIR}/sdllopan.gif | \
		${LOCALBASE}/bin/pamscale .1 | ${LOCALBASE}/bin/pnmtopng > sdllopan.png)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lopan ${PREFIX}/bin/sdllopan
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/sdllopan.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
