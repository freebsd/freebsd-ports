# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	bubble-chains
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://bubble-chains.sintegrial.com/files/
DISTNAME=	chains-${DISTVERSION}
EXTRACT_SUFX=	-src.7z

MAINTAINER=	nemysis@gmx.ch
COMMENT=	The aim is to remove all of the targets on each level

LICENSE=	GPLv2

EXTRACT_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip
BUILD_DEPENDS=		7z:${PORTSDIR}/archivers/p7zip

WRKSRC=		${WRKDIR}/chains-${PORTVERSION}-src

USE_SDL=	sdl image mixer
USE_GL=		glut glew glu
USE_XORG=	xrandr
USE_QT4=	moc_build qmake_build rcc_build uic_build iconengines imageformats \
		corelib svg xml opengl network


PORTDOCS=	README

DESKTOP_ENTRIES="Bubble Chains" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

P7ZIP_CMD=	${LOCALBASE}/bin/7z
P7ZIP_ARGS=	x -o${WRKDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${P7ZIP_CMD} ${P7ZIP_ARGS} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/games/chains|${DATADIR}|' \
		${WRKSRC}/main.cpp ${WRKSRC}/Game.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/chains ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/images/logo.png \
		${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/icon.ico \
		${PREFIX}/share/pixmaps/${PORTNAME}.ico

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
