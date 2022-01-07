PORTNAME=	pcl
DISTVERSION=	1.12.1
CATEGORIES=	graphics math
MASTER_SITES=	https://github.com/PointCloudLibrary/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/
PKGNAMESUFFIX=	-pointclouds
DISTNAME=	source
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${DISTVERSION}

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

USES=		cmake compiler:c++14-lang eigen:3 jpeg localbase:ldflags python xorg
USE_XORG=	x11 xext xt ice sm
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

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
QHULL_LIB_DEPENDS=	libqhull_r.so:math/qhull8

QT5_CMAKE_BOOL=		WITH_QT
QT5_BROKEN=		WITH_QT doesn't do anything, should be used by apps, but apps is also broken: see https://github.com/PointCloudLibrary/pcl/issues/2642

VTK_DESC=		Build VTK-Visualizations
VTK_CMAKE_BOOL=		WITH_VTK
VTK_LIB_DEPENDS=	libvtkCommonCore-8.2.so:math/vtk8
VTK_BROKEN=		VTK has missing ompxx symbols: https://gitlab.kitware.com/vtk/vtk/issues/17444

.include <bsd.port.mk>
