# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osgearth
PORTVERSION=	2.10.1
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	10
CATEGORIES=	graphics geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	C++ terrain rendering toolkit for OpenSceneGraph

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libosg.so:graphics/osg34 \
		libgdal.so:graphics/gdal \
		libcurl.so:ftp/curl \
		libgeos.so:graphics/geos \
		libleveldb.so:databases/leveldb \
		libPocoUtil.so:devel/poco \
		libprotoc.so:devel/protobuf \
		librocksdb.so:databases/rocksdb

USES=		cmake gl pkgconfig sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	gwaldron

USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_GL+=	gl glu

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:PATH=${LOCALBASE}/include \
		-DCMAKE_LIBRARY_PATH:PATH=${LOCALBASE}/lib \
		-DLIB_POSTFIX:STRING=""

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CXXFLAGS+=	-DNO_WARN_X86_INTRINSICS -maltivec -mvsx
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-i386
.endif

.include <bsd.port.post.mk>
