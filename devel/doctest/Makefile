PORTNAME=	doctest
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.3
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	Header-only C++ unit-testing
WWW=		https://github.com/onqtam/doctest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	doctest

CMAKE_OFF=	DOCTEST_WITH_TESTS
CMAKE_TESTING_ON=	DOCTEST_WITH_TESTS

post-stage:
	${INSTALL_LIB} ${BUILD_WRKSRC}/libdoctest_with_main.a	\
		${STAGEDIR}${PREFIX}/lib/libdoctest.a

.include <bsd.port.mk>
