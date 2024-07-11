PORTNAME=	duckstation
PORTVERSION=	20240614
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation emulator
WWW=	https://www.duckstation.org

LICENSE=	GPLv3

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	src/common/fastjmp.cpp:186:2: error: Unknown platform

LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libwebp.so:graphics/webp \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libcurl.so:ftp/curl \
		libwayland-client.so:graphics/wayland \
		libwayland-egl.so:graphics/wayland \
		libbacktrace.so:devel/libbacktrace \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libdbus-1.so:devel/dbus \
		libxkbcommon.so:x11/libxkbcommon
# XXX Necessary for Qt6/FindWrapVulkanHeaders.cmake
#BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++20-lang gl jpeg kde:5 pkgconfig qt:6 sdl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	stenzek
# See: https://github.com/stenzek/duckstation/commits/latest
GH_TAGNAME=	v0.1-6937

USE_GL=		egl
USE_SDL=	sdl2
USE_XORG=	ice x11 xext xrandr xrender
USE_QT=		base tools
USE_KDE=	ecm:build

# XXX Vulkan support needs libshaderc_shared.so:graphics/shaderc but
# Duckstation embeds its own -patched/incompatible- version
# (see: scripts/shaderc-changes.patch) so we just disable it for now.
CMAKE_ARGS+=	\
		-DDUCKSTATION_APPLICATION_DIR_PATH:STRING=${DATADIR} \
		-DENABLE_VULKAN:BOOL=OFF

# - Program and resources are copied from target dir ${CONFIGURE_WRKSRC}/bin
#   because only necessary resources are installed there
do-install:
	cd ${CONFIGURE_WRKSRC}/bin && \
		${COPYTREE_SHARE} resources/ ${STAGEDIR}${DATADIR}/ && \
		${COPYTREE_SHARE} translations/ ${STAGEDIR}${DATADIR}/
	${INSTALL_PROGRAM} \
		${CONFIGURE_WRKSRC}/bin/duckstation-qt ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/bin/resources/images/duck.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/duckstation.png
	${INSTALL_DATA} ${FILESDIR}/duckstation.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
