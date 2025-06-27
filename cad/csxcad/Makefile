PORTNAME=	csxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	6
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to describe geometrical objects
WWW=		https://github.com/thliebig/CSXCAD

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfparser-4.5.so:math/fparser \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmpfr.so:math/mpfr \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-${VTK_VER}.so:math/vtk${VTK_VER:R}

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DFPARSER_ROOT_DIR=${LOCALBASE} \
		-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-${VTK_VER}

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
