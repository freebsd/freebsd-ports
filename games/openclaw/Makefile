PORTNAME=	OpenClaw
DISTVERSION=	0.3-98
DISTVERSIONSUFFIX=	-g3586dfa
PORTREVISION=	6
CATEGORIES=	games

PATCH_SITES=	https://github.com/valpackett/${GH_PROJECT}/commit/
PATCHFILES+=	005aa1d36cae.patch:-p1 # fix running without launcher

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reimplementation of Captain Claw (1997) platformer
WWW=		https://github.com/pjasicek/OpenClaw

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	pjasicek
USE_SDL=	gfx2 image2 mixer2 ttf2

CMAKE_ARGS+=	-DDEFAULT_ASSETS_FOLDER=${DATADIR}/

PLIST_FILES=	bin/openclaw
PORTDATA=	ASSETS.ZIP SAVES.XML clacon.ttf config.xml console02.tga
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LAUNCHER
OPTIONS_DEFAULT=	LAUNCHER

LAUNCHER_DESC=	Install launcher to manage game settings
LAUNCHER_USES=	magick:6,build mono
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
