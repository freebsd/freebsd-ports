# $FreeBSD$

PORTNAME=	hyperscan
PORTVERSION=	4.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc
MASTER_SITES=	GH:hs SF/boost/boost/1.59.0:boost
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:hs boost_1_59_0.tar.gz:boost

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	High-performance multiple regex matching library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ragel:${PORTSDIR}/devel/ragel

USE_GITHUB=	yes
GH_ACCOUNT=	01org
USES=	compiler:c++11-lib cmake:outsource python:build pkgconfig
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	SSSE3 is required for work

CMAKE_BUILD_TYPE=	MinSizeRel
CXXFLAGS+=	-march=core2
CFLAGS+=	-march=core2
CMAKE_ARGS+=	-DBOOST_ROOT=${WRKDIR}/boost_1_59_0

post-stage:
	${MV} ${STAGEDIR}/${PREFIX}/lib/pkgconfig/libhs.pc \
		${STAGEDIR}/${PREFIX}/libdata/pkgconfig/
	${RMDIR} ${STAGEDIR}/${PREFIX}/lib/pkgconfig/

.include <bsd.port.mk>
