PORTNAME=	pcl
DISTVERSION=	1.12.1
PORTREVISION=	3
CATEGORIES=	graphics math
MASTER_SITES=	https://github.com/PointCloudLibrary/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/
PKGNAMESUFFIX=	-pointclouds
DISTNAME=	source
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${DISTVERSION}

# backport of patches fixing tests
PATCH_SITES=	https://github.com/PointCloudLibrary/pcl/commit/
PATCHFILES=	ba388061b0f9ed9584e57d6019c30b044a657c3e.patch:-p1 \
		614e19d96bd8415dbfb52d86df0f3774a9f462fe.patch:-p1 \
		09c76582b5ff0f2b942609f5c85744f1ce96e332.patch:-p1 \
		5be6766fbb8f5e9b2fe97a077dd5be53e5fc6983.patch:-p1 \
		09ea81f995f00b9565037b0fafe121eccfe4cf57.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Point Cloud Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=		undefined reference to `__atomic_load'
NOT_FOR_ARCHS=		armv6 armv7
NOT_FOR_ARCHS_REASON=	common/include/pcl/pcl_macros.h:420:4: error: aligned_malloc not supported on your platform

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libflann_cpp.so:math/flann \
		libfreetype.so:print/freetype2 \
		liblz4.so:archivers/liblz4 \
		libpcap.so:net/libpcap \
		libtiff.so:graphics/tiff

USES=		cmake:testing compiler:c++14-lang eigen:3 jpeg localbase:ldflags python xorg
USE_XORG=	x11 xext xt ice sm
USE_LDCONFIG=	yes

USE_GITHUB=	nodefault
GH_ACCOUNT=	google:gtest
GH_PROJECT=	googletest:gtest
GH_TAGNAME=	release-1.11.0:gtest

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # workaround, otherwise USE_GITHUB=nodefault doesn't work #'

CMAKE_TESTING_ON=	BUILD_global_tests # 6 tests are known to fail: https://github.com/PointCloudLibrary/pcl/issues/5127
CMAKE_TESTING_TARGET=	tests
CMAKE_ARGS=		-DGTEST_SRC_DIR=${WRKSRC_gtest}/googletest -DGTEST_INCLUDE_DIR=${WRKSRC_gtest}/googletest/include

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:R}

DATADIR=	${PREFIX}/share/${PORTNAME}-${DISTVERSION:R}  # match the directory where the project installs .cmake files

OPTIONS_DEFINE=		OPENGL PNG QHULL QT5 VTK
OPTIONS_DEFAULT=	PNG # QHULL is disabled due to conflicts qhull8 vs. qhull
OPTIONS_SUB=		yes

OPENGL_CMAKE_BOOL=	WITH_OPENGL # it finds OpenGL, but no binaries are linked with it: https://github.com/PointCloudLibrary/pcl/issues/2641
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

QHULL_DESC=		Include convex-hull operations
QHULL_CMAKE_BOOL=	WITH_QHULL
QHULL_LIB_DEPENDS=	libqhull_r.so:math/qhull8

QT5_CMAKE_ON=		-DWITH_QT=QT5
QT5_CMAKE_OFF=		-DWITH_QT=NO
QT5_BROKEN=		WITH_QT doesn't do anything, should be used by apps, but apps is also broken: see https://github.com/PointCloudLibrary/pcl/issues/2642

VTK_DESC=		Build VTK visualizations
VTK_USES=		gl qt:5
VTK_USE=		GL=gl,glu QT=core,gui,opengl,widgets,buildtools_build,qmake_build
VTK_CMAKE_BOOL=		WITH_VTK
VTK_CMAKE_ON=		-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.1
VTK_LIB_DEPENDS=	libvtkCommonCore-9.1.so:math/vtk9

.include <bsd.port.mk>
