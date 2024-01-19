PORTNAME=	openmvs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Multi-View Stereo reconstruction library
WWW=		https://github.com/cdcseacave/openMVS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		compilation is broken because of the use of discontinued C++ features, see https://github.com/cdcseacave/openMVS/issues/1075
BROKEN_aarch64=	use of undeclared identifier '__builtin_ia32_emms' # https://github.com/cdcseacave/openMVS/issues/847

BUILD_DEPENDS=	cgal>0:math/cgal \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		vcglib>0:devel/vcglib
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libceres.so:math/ceres-solver \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopencv_core.so:graphics/opencv \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake:testing compiler:c++17-lang eigen:3 jpeg

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
