# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bubble-chains
PORTVERSION=	0.1.1
PORTREVISION=	9
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2D arcade-puzzle game based on Qt/SDL

LICENSE=	GPLv2

BUILD_DEPENDS=	icotool:graphics/icoutils

USE_GITHUB=	yes
GH_ACCOUNT=	SanskritFritz

USES=		dos2unix qmake
DOS2UNIX_GLOB=	*.pro *.cpp  *.h *.ui *.rc *.htm *.dat *.css
USE_SDL=	mixer sdl
USE_GL=		gl
USE_XORG=	xrandr
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run \
		corelib svg xml opengl network
QMAKE_SOURCE_PATH=	${WRKSRC}/Game.pro

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Bubble Chains" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|bin/chains|bin/bubble-chains|; \
		 s|/usr/bin|${PREFIX}/bin|; \
		 s|/usr/share/chains|${DATADIR}|' \
		${WRKSRC}/Game.pro
	@${REINPLACE_CMD} -e 's|/usr/share/chains|${DATADIR}|' \
		${WRKSRC}/main.cpp

post-build:
.for i in 16 32 48
	@${MKDIR} ${WRKDIR}/icons/hicolor/${i}x${i}/apps
	${LOCALBASE}/bin/icotool -x -b 32 -w ${i} \
		-o ${WRKDIR}/icons/hicolor/${i}x${i}/apps/bubble-chains.png \
		${WRKSRC}/icon.ico
.endfor

post-install:
	cd ${WRKDIR} && ${COPYTREE_SHARE} icons ${STAGEDIR}${PREFIX}/share

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
