PORTNAME=	duckstation
PORTVERSION=	20231124
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free and open-source PlayStation emulator
WWW=	https://www.duckstation.org

LICENSE=	GPLv3

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	src/common/fastjmp.cpp:186:2: error: Unknown platform

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libbacktrace.so:devel/libbacktrace \
		libxkbcommon.so:x11/libxkbcommon \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libsndio.so:audio/sndio \
		libdbus-1.so:devel/dbus
# XXX Necessary for Qt6/FindWrapVulkanHeaders.cmake
BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++20-lang gl pkgconfig qt:6 sdl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	stenzek
# See: https://github.com/stenzek/duckstation/commits/latest
GH_TAGNAME=	2739794

USE_GL=		egl
USE_SDL=	sdl2
USE_XORG=	ice x11 xext xrandr xrender
USE_QT=		base tools

CMAKE_ARGS+=	\
		-DDUCKSTATION_APPLICATION_DIR_PATH:STRING=${DATADIR}

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
