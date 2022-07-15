PORTNAME=	openmvs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Multi-View Stereo reconstruction library

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_arm64=	use of undeclared identifier '__builtin_ia32_emms'

BUILD_DEPENDS=	cgal>0:math/cgal \
		${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo \
		vcglib>0:devel/vcglib
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libceres.so:math/ceres-solver \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopencv_core.so:graphics/opencv \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake compiler:c++17-lang eigen:3 jpeg

USE_GITHUB=	yes
GH_ACCOUNT=	cdcseacave
GH_PROJECT=	openMVS

CMAKE_ON=	BUILD_SHARED_LIBS OpenMVS_USE_CERES
CMAKE_OFF=	OpenMVS_BUILD_TOOLS # tools can't be built because of https://github.com/cdcseacave/openMVS/issues/846
CMAKE_ARGS=	-DVCG_ROOT=${LOCALBASE}/include/vcglib

.include <bsd.port.mk>
