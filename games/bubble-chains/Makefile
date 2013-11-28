# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	bubble-chains
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://bubble-chains.sintegrial.com/files/
DISTNAME=	chains-${DISTVERSION}
EXTRACT_SUFX=	-src.7z

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	The aim is to remove all of the targets on each level

LICENSE=	GPLv2

EXTRACT_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip
BUILD_DEPENDS=		7z:${PORTSDIR}/archivers/p7zip

WRKSRC=		${WRKDIR}/chains-${PORTVERSION}-src

USES=		qmake
USE_SDL=	sdl image mixer
USE_GL=		glut glew glu
USE_XORG=	xrandr
USE_DOS2UNIX=	*.pro *.cpp  *.h *.ui *.ui *.rc *.htm *.dat *.css
USE_QT4=	moc_build rcc_build uic_build iconengines_run imageformats_run \
		corelib svg xml opengl network
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lSDL-1.2

PORTDOCS=	README

DESKTOP_ENTRIES="Bubble Chains" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" true

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

P7ZIP_CMD=	${LOCALBASE}/bin/7z
P7ZIP_ARGS=	x -o${WRKDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${P7ZIP_CMD} ${P7ZIP_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/chains|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro

post-configure:
	@${REINPLACE_CMD} -e 's|CFLAGS        =|CFLAGS        ?=|' \
		-e 's|CXXFLAGS      =|CXXFLAGS     ?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chains ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/images/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/icon.ico \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
