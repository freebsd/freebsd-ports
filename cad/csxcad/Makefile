PORTNAME=	csxcad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2-103
DISTVERSIONSUFFIX=	-g3c4fb66
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library to describe geometrical objects

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfparser-4.5.so:math/fparser \
		libgmp.so:math/gmp \
		libhdf5.so:science/hdf5 \
		libmpfr.so:math/mpfr \
		libsz.so:science/szip \
		libtinyxml.so:textproc/tinyxml \
		libvtkCommonMath-9.0.so:math/vtk9

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	thliebig
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ARGS=	-DFPARSER_ROOT_DIR=${LOCALBASE}

.include <bsd.port.mk>
