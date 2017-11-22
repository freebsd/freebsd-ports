# $FreeBSD$

PORTNAME=	OpenClaw
DISTVERSION=	0.0-51
DISTVERSIONSUFFIX=	-gbac7730
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Reimplementation of Captain Claw (1997) platformer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USES=		cmake:outsource compiler:c++11-lib pkgconfig localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	pjasicek
USE_SDL=	gfx2 image2 mixer2 ttf2

PLIST_FILES=	bin/openclaw
PORTDATA=	ASSETS.ZIP SAVES.XML clacon.ttf config.xml console02.tga
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LAUNCHER
OPTIONS_DEFAULT=	LAUNCHER

LAUNCHER_DESC=	Install launcher to manage game settings
LAUNCHER_USES=	mono
LAUNCHER_BUILD_DEPENDS=	convert:graphics/ImageMagick
LAUNCHER_PLIST_FILES=	bin/ClawLauncher.exe bin/clawlauncher
LAUNCHER_DESKTOP_ENTRIES=	\
		"${GH_PROJECT}" \
		"" \
		"${PORTNAME:tl}" \
		"clawlauncher" \
		"Game;ArcadeGame;" \
		""

post-patch:
	@${REINPLACE_CMD} '/CMAKE_RUNTIME_OUTPUT_DIRECTORY/d; s| -O2 -g||' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/share/openclaw|${DATADIR}|g' \
		${WRKSRC}/Build_Release/clawlauncher \
		${WRKSRC}/Build_Release/config_linux_release.xml

pre-build:
	@cd ${WRKSRC}/Build_Release && ${CP} config_linux_release.xml config.xml

post-build-LAUNCHER-on:
	@convert -verbose -set filename:size %wx%h \
		${WRKSRC}/ClawLauncher/Resources/launcher_icon.ico \
		${WRKDIR}/launcher_icon_%\[filename:size].png

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME:tl} \
		${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/Build_Release && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR}

do-install-LAUNCHER-on:
	${INSTALL_SCRIPT} ${WRKSRC}/Build_Release/ClawLauncher.exe \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Build_Release/clawlauncher \
		${STAGEDIR}${PREFIX}/bin
.for size in 16x16 24x24 32x32 48x48 64x64 96x96 128x128 192x192 256x256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKDIR}/launcher_icon_${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps/${PORTNAME:tl}.png
	@${ECHO_CMD} share/icons/hicolor/${size}/apps/${PORTNAME:tl}.png >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
