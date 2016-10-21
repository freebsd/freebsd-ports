# $FreeBSD$

PORTNAME=	hyperscan
PORTVERSION=	4.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc
MASTER_SITES=	SF/boost/boost/1.59.0:boost
DISTFILES=	boost_1_59_0.tar.gz:boost

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	High-performance multiple regex matching library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ragel:devel/ragel

USE_GITHUB=	yes
GH_ACCOUNT=	01org
USES=	compiler:c++11-lib cmake:outsource pathfix python:build pkgconfig
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	SSSE3 is required for work

OPTIONS_DEFINE=	SHARED NATIVE
SHARED_DESC=		Build shared library
NATIVE_DESC=		Build with native CPU tunes
OPTIONS_DEFAULT=	SHARED

.ifndef DEBUG_FLAGS
CMAKE_BUILD_TYPE=	Release
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
		SOSHORTVERSION=${PORTVERSION:C/\.[0-9].[0-9]$//}
.else
PLIST_SUB+=	SHARED="@comment "
.endif

.include <bsd.port.mk>
