PORTNAME=	supercollider
DISTVERSION=	3.14.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/Version-${DISTVERSION}/
DISTNAME=	SuperCollider-${DISTVERSION}-Source

MAINTAINER=	ports@nicandneal.net
COMMENT=	Programming language for real time audio synthesis
WWW=		https://supercollider.github.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3 \
		vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libfftw3f.so:math/fftw3-float \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++11-lang gl iconv localbase pkgconfig qt:6 \
		readline shared-mime-info tar:bzip2 xorg
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_QT=		base svg tools
USE_XORG=	x11 xt

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/qt6 \
		-DLIBUSB_1_INCLUDE_DIR=/usr/include \
		-DLIBUSB_1_LIBRARY=/usr/lib/libusb.so
CMAKE_ON=	LIBSCSYNTH \
		SC_QT \
		SYSTEM_BOOST \
		SYSTEM_YAMLCPP
CMAKE_OFF=	SC_ABLETON_LINK

DESKTOP_ENTRIES="SuperCollider IDE" "" "${PREFIX}/share/pixmaps/sc_ide.svg" \
		"scide" "" false

OPTIONS_DEFINE=		AVAHI DOCS SUPERNOVA WEBENGINE
OPTIONS_DEFINE_amd64=	SSE2 SSE
OPTIONS_DEFINE_i386=	SSE2 SSE
OPTIONS_DEFAULT=	AVAHI SUPERNOVA
OPTIONS_DEFAULT_amd64=	SSE2 SSE WEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_SUB=		yes

DOCS_DESC=		Install on-line help text
SSE2_DESC=		${SSE_DESC:S|SSE|SSE2|}
SUPERNOVA_DESC=		Build with supernova as optional audio synthesis server

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
			libavahi-common.so:net/avahi-app
AVAHI_CMAKE_BOOL_OFF=	NO_AVAHI
DOCS_CMAKE_BOOL=	INSTALL_HELP
SSE2_CMAKE_BOOL=	SSE2
SSE_CMAKE_BOOL=		SSE
SUPERNOVA_CMAKE_BOOL=	SUPERNOVA
WEBENGINE_USE=		qt=declarative,positioning,webengine,webchannel,websockets
WEBENGINE_CMAKE_BOOL=	SC_USE_QTWEBENGINE

.include <bsd.port.mk>
