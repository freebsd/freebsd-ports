# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alembic
PORTVERSION=	1.7.9
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open framework for storing and sharing graphic scene data

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libImath.so:graphics/ilmbase

USES=		cmake compiler:c++11-lang
USE_CXXSTD=	c++11
USE_GITHUB=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	HDF5
OPTIONS_DEFAULT=	HDF5
OPTIONS_SUB=	yes

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_ON=	-DUSE_HDF5:BOOL=ON

PLIST_FILES=	lib/libAlembic.so.${PORTVERSION} \
		lib/libAlembic.so.${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's,H5Rdereference,&1,' \
		${WRKSRC}/lib/Alembic/AbcCoreHDF5/HDF5Util.cpp

.include <bsd.port.mk>
