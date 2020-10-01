# $FreeBSD$

PORTNAME=	supercollider
DISTVERSION=	3.11.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/supercollider/supercollider/releases/download/Version-${PORTVERSION}/
DISTNAME=	SuperCollider-${PORTVERSION}-Source

MAINTAINER=	ports@nicandneal.net
COMMENT=	Programming language for real time audio synthesis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libfftw3f.so:math/fftw3-float \
		libyaml-cpp.so:devel/yaml-cpp

USES=		cmake compiler:c++11-lang iconv localbase pkgconfig \
		qt:5 readline shared-mime-info tar:bzip2 xorg
USE_QT=		buildtools_build concurrent core declarative gui linguisttools location \
		network opengl printsupport qmake_build sensors \
		sql widgets websockets webchannel svg
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib/qt5 \
		-DLIBUSB_1_INCLUDE_DIR=/usr/include \
		-DLIBUSB_1_LIBRARY=/usr/lib/libusb.so \
		-DLIBSCSYNTH=ON \
		-DSYSTEM_BOOST=ON \
		-DSYSTEM_YAMLCPP=ON \
		-DSC_ABLETON_LINK=OFF

DESKTOP_ENTRIES="SuperCollider IDE" "" "${LOCALBASE}/share/pixmaps/sc_ide.svg" \
		"scide" "" false

OPTIONS_DEFINE=		AVAHI HELP SUPERNOVA
OPTIONS_DEFAULT=	AVAHI HELP SUPERNOVA
OPTIONS_SUB=	yes

HELP_DESC=	Install on-line help text
SUPERNOVA_DESC=	Build with supernova as optional audio synthesis server

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
			libavahi-common.so:net/avahi-app
AVAHI_CMAKE_BOOL_OFF=	NO_AVAHI
HELP_CMAKE_BOOL=	INSTALL_HELP
SUPERNOVA_CMAKE_BOOL=	SUPERNOVA

.include <bsd.port.pre.mk>

.if ! ${ARCH} == amd64 && ! ${ARCH} == i386
CMAKE_ARGS+=	-DSSE:BOOL=FALSE -DSSE2:BOOL=FALSE -DSC_USE_QTWEBENGINE:BOOL=FALSE
.else
USE_QT+=	webengine
.endif

.include <bsd.port.post.mk>
