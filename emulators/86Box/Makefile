PORTNAME=	86Box
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2
CATEGORIES=	emulators

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Emulator of x86-based machines based on PCem
WWW=		https://86box.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le

BUILD_DEPENDS=	evdev-proto>=5.8:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libfluidsynth.so:audio/fluidsynth \
		libfreetype.so:print/freetype2 \
		libopenal.so:audio/openal-soft \
		libpng.so:graphics/png \
		librtmidi.so:audio/rtmidi \
		libslirp.so:net/libslirp \
		libsndfile.so:audio/libsndfile \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gl gnome pkgconfig qmake qt:6 sdl \
		xorg
USE_GITHUB=	yes
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base tools:build
USE_SDL=	sdl2
USE_XORG=	x11 xcb xext xi

BUILD_DEPENDS+=	vulkan-headers>0:graphics/vulkan-headers
CMAKE_ON=	USE_QT6

CMAKE_ON+=		${CMAKE_ON_${ARCH}} RELEASE
CMAKE_ON_aarch64=	NEW_DYNAREC
CMAKE_OFF=		${CMAKE_OFF_${ARCH}} DISCORD
CMAKE_OFF_powerpc64le=	DYNAREC

CXXFLAGS+=	-I${LOCALBASE}/include/qt6/QtGui/`pkg-config --modversion Qt6Gui`/QtGui

SUB_FILES=	86Box-install-roms.sh
SUB_LIST=	DISTVERSION=${DISTVERSION} \
		DISTVERSIONPREFIX=${DISTVERSIONPREFIX}

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USES=		kde:5
WAYLAND_USE=		KDE=ecm:build
WAYLAND_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Wayland:BOOL=ON

ICON_RESOLUTIONS=	128x128 192x192 256x256 48x48 512x512 64x64 72x72 96x96

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/src/86Box ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/86Box-install-roms.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/unix/assets/net.86box.86Box.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for F in ${ICON_RESOLUTIONS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${F}/apps
	${INSTALL_DATA} ${WRKSRC}/src/unix/assets/${F}/net.86box.86Box.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${F}/apps
.endfor

.include <bsd.port.mk>
