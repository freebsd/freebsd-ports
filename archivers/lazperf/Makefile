PORTNAME=	lazperf
DISTVERSION=	3.4.0
CATEGORIES=	archivers databases geography

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Alternative LAZ implementation for C++ and JavaScript
WWW=		https://github.com/hobu/laz-perf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	hobu
GH_PROJECT=	laz-perf

CMAKE_OFF=	WITH_TESTS

.include <bsd.port.mk>
