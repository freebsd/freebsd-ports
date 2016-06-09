# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	osgearth
PORTVERSION=	2.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	graphics geography

MAINTAINER=	coder@tuxfamily.org
COMMENT=	C++ terrain rendering toolkit for OpenSceneGraph

LICENSE=	LGPL3

BUILD_DEPENDS=	minizip:archivers/minizip
LIB_DEPENDS=	libosg.so:graphics/osg \
		libgdal.so:graphics/gdal \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron

USE_LDCONFIG=	yes
USES=		cmake gmake pkgconfig sqlite
PLIST_SUB=	OSGVERSION=3.4.0

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DMINIZIP_INCLUDE_DIR=${LOCALBASE}/include/minizip \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING="" \
		-DOSGEARTH_USE_QT:BOOL=FALSE

.include <bsd.port.mk>
