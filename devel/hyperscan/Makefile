# $FreeBSD$

PORTNAME=	hyperscan
PORTVERSION=	4.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc
MASTER_SITES=	GH:hs SF/boost/boost/1.59.0:boost
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:hs boost_1_59_0.tar.gz:boost

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	High-performance multiple regex matching library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ragel:devel/ragel

USE_GITHUB=	yes
GH_ACCOUNT=	01org
USES=	compiler:c++11-lib cmake:outsource python:build pkgconfig
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	SSSE3 is required for work

OPTIONS_DEFINE=	SHARED NATIVE
SHARED_DESC=		Build shared library
NATIVE_DESC=		Build with native CPU tunes

.ifndef DEBUG_FLAGS
CMAKE_BUILD_TYPE=	MinSizeRel
.else
CMAKE_BUILD_TYPE=	Debug
.endif

CMAKE_ARGS+=	-DBOOST_ROOT=${WRKDIR}/boost_1_59_0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNATIVE}
CXXFLAGS+=	-march=native -mtune=native
CFLAGS+=	-march=native -mtune=native
.else
CXXFLAGS+=	-march=core2
CFLAGS+=	-march=core2
.endif

.if ${PORT_OPTIONS:MSHARED}
CMAKE_ARGS+=	-DBUILD_STATIC_AND_SHARED=ON
PLIST_SUB+=	SHARED="" \
		SOVERSION=${PORTVERSION} \
		SOSHORTVERSION=${PORTVERSION:C/\.[0-9]$//}
.else
PLIST_SUB+=	SHARED="@comment "
.endif

post-stage:
	${MV} ${STAGEDIR}/${PREFIX}/lib/pkgconfig/libhs.pc \
		${STAGEDIR}/${PREFIX}/libdata/pkgconfig/
	${RMDIR} ${STAGEDIR}/${PREFIX}/lib/pkgconfig/

.include <bsd.port.mk>
