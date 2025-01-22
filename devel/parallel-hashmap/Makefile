PORTNAME=	parallel-hashmap
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of excellent hash map implementations (a C++ header-only library)
WWW=		https://github.com/greg7mdp/parallel-hashmap

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	greg7mdp

CMAKE_OFF=	PHMAP_BUILD_TESTS PHMAP_BUILD_EXAMPLES
CMAKE_TESTING_ON=	PHMAP_BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

# tests as of 2.0.0: 100% tests passed, 0 tests failed out of 17

.include <bsd.port.mk>
