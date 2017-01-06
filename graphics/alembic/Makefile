# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alembic
PORTVERSION=	1.5.8
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open framework for storing and sharing graphic scene data

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath-2_2.so:graphics/ilmbase \
		libhdf5.so:science/hdf5

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang
USE_CXXSTD=	c++11
USE_GL=		glew glut

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON -DUSE_PYALEMBIC:BOOL=OFF

# Alembic < 1.6.0's AlembicHDF5.cmake sets HDF5_ROOT to a bogus value if one is
# not specified, and this confuses CMake >= 3.6.0 which started honoring
# HDF5_ROOT more thoroughly.
CMAKE_ARGS+=	-DHDF5_ROOT:PATH="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's,H5Rdereference,&1,' \
		${WRKSRC}/lib/Alembic/AbcCoreHDF5/HDF5Util.cpp

.include <bsd.port.mk>
