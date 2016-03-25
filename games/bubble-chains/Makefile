# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bubble-chains
PORTVERSION=	0.1.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://bubble-chains.sintegrial.com/files/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	chains-${DISTVERSIONFULL}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTFILES:N*\:icons:C/:.*//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The aim is to remove all of the targets on each level

LICENSE=	GPLv2

BROKEN=		unfetchable
DEPRECATED=	does not fetch
EXPIRATION_DATE=2016-04-23

WRKSRC=		${WRKDIR}/chains-${DISTVERSION}-src

USES=		7z dos2unix qmake
DOS2UNIX_GLOB=	*.pro *.cpp  *.h *.ui *.ui *.rc *.htm *.dat *.css
USE_SDL=	sdl image mixer
USE_GL=		glut glew glu
USE_XORG=	xrandr
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run \
		corelib svg xml opengl network
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lSDL

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Bubble Chains" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/chains|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro

post-configure:
	@${REINPLACE_CMD} -e 's|CFLAGS        =|CFLAGS        ?=|; \
		s|CXXFLAGS      =|CXXFLAGS     ?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chains \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/icon.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
