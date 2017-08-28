# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	osgearth
PORTVERSION=	2.8
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	graphics geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	C++ terrain rendering toolkit for OpenSceneGraph

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	minizip:archivers/minizip
LIB_DEPENDS=	libosg.so:graphics/osg \
		libgdal.so:graphics/gdal \
		libcurl.so:ftp/curl

USES=		cmake pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron

USE_LDCONFIG=	yes
USE_GL+=	gl glu
PLIST_SUB=	OSGVERSION=3.4.0

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DMINIZIP_INCLUDE_DIR=${LOCALBASE}/include/minizip \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING="" \
		-DOSGEARTH_USE_QT:BOOL=FALSE

.include <bsd.port.mk>
