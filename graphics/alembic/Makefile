# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alembic
PORTVERSION=	1.5.8
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open framework for storing and sharing graphic scene data

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath-2_2.so:graphics/ilmbase \
		libhdf5.so:science/hdf5

BROKEN_FreeBSD_9=	does not build (insufficient C++11 support)

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang
USE_CXXSTD=	c++11
USE_GL=		glew glut

CMAKE_ARGS=	-DBUILD_SHARED_LIBS:BOOL=ON -DUSE_PYALEMBIC:BOOL=OFF

post-patch:
	@${REINPLACE_CMD} -e 's,H5Rdereference,&1,' \
		${WRKSRC}/lib/Alembic/AbcCoreHDF5/HDF5Util.cpp

.include <bsd.port.mk>
