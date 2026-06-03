PORTNAME=	openmvs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Multi-View Stereo reconstruction library
WWW=		https://github.com/cdcseacave/openMVS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libceres.so:math/ceres-solver \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopencv_core.so:graphics/opencv \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		${PY_BOOST} \
		libpython${PYTHON_VER}${PYTHON_ABIVER}.so:lang/python${PYTHON_SUFFIX}
BUILD_DEPENDS=	cgal>0:math/cgal \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		vcglib>0:devel/vcglib

USES=		cmake:testing compiler:c++14-lang eigen:3 jpeg python

USE_GITHUB=	yes
GH_ACCOUNT=	cdcseacave
GH_PROJECT=	openMVS

CMAKE_ON=	BUILD_SHARED_LIBS OpenMVS_USE_CERES
CMAKE_OFF=	OpenMVS_BUILD_TOOLS # tools can't be built because of https://github.com/cdcseacave/openMVS/issues/846
CMAKE_OFF+=	OpenMVS_ENABLE_TESTS
CMAKE_ARGS=	-DVCG_ROOT=${LOCALBASE}/include/vcglib
CMAKE_TESTING_ON=	OpenMVS_ENABLE_TESTS # tests fail to configure, see https://github.com/cdcseacave/openMVS/issues/911

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
CMAKE_ARGS+=	-DOpenMVS_USE_SSE:BOOL=OFF
.endif

.include <bsd.port.mk>
