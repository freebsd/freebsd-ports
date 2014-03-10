# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	osgearth
PORTVERSION=	2.5
CATEGORIES=	graphics geography
MASTER_SITES=	https://github.com/gwaldron/${PORTNAME}/archive/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	osgEarth is a C++ terrain rendering toolkit for OpenSceneGraph

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/bin/minizip:${PORTSDIR}/archivers/minizip
LIB_DEPENDS=	libosg.so:${PORTSDIR}/graphics/osg \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libcurl.so:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

USE_LDCONFIG=	YES
USE_SQLITE=	3
USES=		cmake gmake pkgconfig zip
PLIST_SUB=	OSGVERSION=3.2.0

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DMINIZIP_INCLUDE_DIR=${LOCALBASE}/include/minizip \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING="" \
		-DOSGEARTH_USE_QT:BOOL=FALSE

.include <bsd.port.mk>
