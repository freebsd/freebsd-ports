# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	osgearth
PORTVERSION=	2.5
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	5
CATEGORIES=	graphics geography

MAINTAINER=	coder@tuxfamily.org
COMMENT=	osgEarth is a C++ terrain rendering toolkit for OpenSceneGraph

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/bin/minizip:${PORTSDIR}/archivers/minizip
LIB_DEPENDS=	libosg.so:${PORTSDIR}/graphics/osg \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libcurl.so:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron

USE_LDCONFIG=	YES
USE_SQLITE=	3
USES=		cmake gmake pkgconfig
PLIST_SUB=	OSGVERSION=3.2.1

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DMINIZIP_INCLUDE_DIR=${LOCALBASE}/include/minizip \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING="" \
		-DOSGEARTH_USE_QT:BOOL=FALSE

.include <bsd.port.mk>
