PORTNAME=	pegtl
DISTVERSION=	4.0.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parsing Expression Grammar Template Library
WWW=		https://github.com/taocpp/PEGTL

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		cmake:testing
USE_GITHUB=	yes

GH_ACCOUNT=	taocpp
GH_PROJECT=	PEGTL

CMAKE_OFF=	PEGTL_BUILD_TESTS PEGTL_BUILD_EXAMPLES
CMAKE_TESTING_ON=	PEGTL_BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

# tests as of 4.0.0: 100% tests passed, 0 tests failed out of 257

.include <bsd.port.mk>
