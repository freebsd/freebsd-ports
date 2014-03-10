# Created by: Pawel Pekala <pawel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigalomania
PORTVERSION=	0.26
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/135701637/
DISTNAME=	${PORTNAME}src

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Open source 2D real time strategy god game

USES=		zip
USE_SDL=	image mixer sdl

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CC=g++|CC=${CXX}|' \
		-e '/^CCFLAGS/ s|-O2|${CXXFLAGS}|' \
		-e 's|-O2 $$(INC)|$$(INC)|' \
		-e 's|/usr/X11R6|${LOCALBASE}|' \
		${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -exec ${GREP} -q "__linux" {} \; \
		-exec ${REINPLACE_CMD} 's|__linux|__FreeBSD__|' {} \;
	@${REINPLACE_CMD} 's|/opt/gigalomania/||g' \
		${WRKSRC}/gigalomania.desktop \
		${WRKSRC}/gigalomania_fullscreen.desktop
	@${REINPLACE_CMD} 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/game.cpp \
		${WRKSRC}/gamestate.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for dir in gfx islands sound
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_fullscreen.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
