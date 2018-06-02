# Created by: lbartoletti <lbartoletti@tuxfamily.org>
# $FreeBSD$

PORTNAME=	lazperf
DISTVERSION=	1.2.0
CATEGORIES=	archivers databases geography

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Alternative LAZ implementation for C++ and JavaScript

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	hobu
GH_PROJECT=	laz-perf

CMAKE_ARGS+=	-DWITH_TESTS:BOOL=FALSE

post-build:
	${RM} ${WRKSRC}/laz-perf/portable_endian.hpp.orig
.include <bsd.port.mk>
