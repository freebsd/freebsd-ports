PORTNAME=	string_theory
PORTVERSION=	3.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/zrax/string_theory/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern C++ library for string manipulation and storage
WWW=		https://github.com/zrax/string_theory

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++20-lang

CMAKE_ON=	ST_ENABLE_STL_FILESYSTEM ST_ENABLE_STL_STRINGS
CMAKE_OFF=	ST_BUILD_PROFILE_TEST ST_BUILD_TESTS ST_BUILD_TEST_COVERAGE
CMAKE_TESTING_ON=	ST_BUILD_TESTS
NO_ARCH=	yes

.include <bsd.port.mk>
