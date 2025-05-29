PORTNAME=	kealib
PORTVERSION=	1.6.2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/ubarsc/kealib/releases/download/kealib-${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HDF5 Based Raster File Format
WWW=		https://kealib.org/ \
		https://github.com/ubarsc/kealib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		cmake

CMAKE_OFF=	HDF5_PREFER_PARALLEL \
		HDF5_USE_STATIC_LIBRARIES \
		LIBKEA_WITH_GDAL
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
