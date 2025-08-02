PORTNAME=	lace
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	devel
PKGNAMESUFFIX=	-work-stealing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of work-stealing in C
WWW=		https://github.com/trolando/lace

BROKEN_i386=	compilation fails: static assertion failed due to requirement '(sizeof(struct _Task) % 64) == 0': Task size should be a multiple of LINE_SIZE

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: static assertion failed due to requirement '(sizeof(struct _Task) % 64) == 0': Task size should be a multiple of LINE_SIZE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	trolando

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		LACE_BUILD_TESTS
CMAKE_TESTING_ON=	LACE_BUILD_TESTS

PORTSCOUT=	limit:^.*[0-9]+\.[0-9]+\.[0-9]+$$ # prevent tags like mucocos_2014_ri

# tests as of 2.0.2: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
