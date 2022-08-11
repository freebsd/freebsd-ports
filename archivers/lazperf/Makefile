PORTNAME=	lazperf
DISTVERSION=	2.0.0
CATEGORIES=	archivers databases geography

PATCH_SITES=	https://github.com/hobu/laz-perf/commit/
PATCHFILES=	a003d1ead4afb9a0c61cde8b00340c489f2ce370.patch:-p1

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Alternative LAZ implementation for C++ and JavaScript

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	hobu
GH_PROJECT=	laz-perf

CMAKE_OFF=	WITH_TESTS

.include <bsd.port.mk>
