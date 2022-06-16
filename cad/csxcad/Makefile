PORTNAME=	csxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-103
DISTVERSIONSUFFIX=	-g3c4fb66
PORTREVISION=	4
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to describe geometrical objects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cgal>0:math/cgal
# many dependencies below are induced by vtk8, but not vtk9
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfparser-4.5.so:math/fparser \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmpfr.so:math/mpfr \
		libpng16.so:graphics/png \
		libsz.so:science/libaec \
		libtiff.so:graphics/tiff \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonCore-8.2.so:math/vtk8 # some related packages don't support vtk9 yet, see https://github.com/thliebig/QCSXCAD/issues/6#issuecomment-901633240

USES=		cmake jpeg pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DFPARSER_ROOT_DIR=${LOCALBASE} \
		-DVTK_DIR=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2

.include <bsd.port.mk>
