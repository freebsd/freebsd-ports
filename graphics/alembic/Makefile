PORTNAME=	alembic
PORTVERSION=	1.8.12
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open framework for storing and sharing graphic scene data
WWW=		http://alembic.io/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libImath.so:math/Imath

USES=		cmake:testing compiler:c++14-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_TESTS
CMAKE_TESTING_ON=	USE_TESTS

OPTIONS_DEFINE=	HDF5
OPTIONS_DEFAULT=	HDF5
OPTIONS_SUB=	yes

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_ON=	-DUSE_HDF5:BOOL=ON

PLIST_FILES=	lib/libAlembic.so.${PORTVERSION} \
		lib/libAlembic.so.${PORTVERSION:R}

.include <bsd.port.mk>
