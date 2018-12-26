# $FreeBSD$

PORTNAME=	pcl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	graphics math
PKGNAMESUFFIX=	-pointclouds

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Point Cloud Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	undefined reference to `__atomic_load'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libflann_cpp.so:math/flann \
		libfreetype.so:print/freetype2 \
		libomp.so:devel/openmp \
		libpcap.so:net/libpcap \
		libtiff.so:graphics/tiff

USES=		cmake eigen:3 jpeg python
USE_GITHUB=	yes
GH_ACCOUNT=	PointCloudLibrary
USE_XORG=	x11 xext xt ice sm
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${DISTVERSION} SHL2=${DISTVERSION:R}

DATADIR=	${PREFIX}/share/${PORTNAME}-${DISTVERSION:R}  # match the directory where the project installs .cmake files

OPTIONS_DEFINE=		OPENGL PNG QHULL QT5 VTK
OPTIONS_DEFAULT=	PNG QHULL
OPTIONS_SUB=		yes

OPENGL_CMAKE_BOOL=	WITH_OPENGL # it finds OpenGL, but no binaries are linked with it: https://github.com/PointCloudLibrary/pcl/issues/2641
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,glu

PNG_CMAKE_BOOL=		WITH_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png

QHULL_DESC=		Include convex-hull operations
QHULL_CMAKE_BOOL=	WITH_QHULL
QHULL_LIB_DEPENDS=	libqhull.so:math/qhull5

QT5_CMAKE_BOOL=		WITH_QT
QT5_BROKEN=		WITH_QT doesn't do anything, should be used by apps, but apps is also broken: see https://github.com/PointCloudLibrary/pcl/issues/2642

VTK_DESC=		Build VTK-Visualizations
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-8.1.so:math/vtk8
VTK_BROKEN=		VTK has missing ompxx symbols: https://gitlab.kitware.com/vtk/vtk/issues/17444

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
# This should also be an port option, but PCL fails to build w/out OpenMP: https://github.com/PointCloudLibrary/pcl/issues/2638
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

post-patch:  # 10 doesn't have std::sqrt, switching to ::sqrt from math.h
	@${GREP} -rl std::sqrt ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|::std::sqrt|::sqrt|g ; s|std::sqrt|::sqrt|g'

.include <bsd.port.mk>
