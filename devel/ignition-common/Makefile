PORTNAME=	ignition-common
DISTVERSIONPREFIX=	ignition-common3_
DISTVERSION=	3.17.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of libraries designed to rapidly develop robot applications
WWW=		https://ignitionrobotics.org/home

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ignition-cmake>=2:devel/ignition-cmake
LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4 \
		libfreeimage.so:graphics/freeimage \
		libgts.so:graphics/gts \
		libtinyxml2.so:textproc/tinyxml2 \
		libuuid.so:misc/libuuid \
		libignition-math6.so:math/ignition-math

USES=		cmake compiler:c++17-lang gnome localbase pkgconfig
USE_CXXSTD=	c++14
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_ON=	USE_EXTERNAL_TINYXML2
CMAKE_OFF=	BUILD_DOCS BUILD_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	gazebosim
GH_PROJECT=	gz-common

PLIST_SUB=	COMMON_IGN_VER=common${DISTVERSION:R:R}

TESTING_UNSAFE=	6 tests failed out of 79

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
