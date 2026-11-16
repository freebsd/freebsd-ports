PORTNAME=	c-ares
DISTVERSION=	1.34.9
CATEGORIES=	dns
MASTER_SITES=	https://github.com/c-ares/c-ares/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for asynchronous DNS requests
WWW=		https://c-ares.org/ \
		https://github.com/c-ares/c-ares

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

CMAKE_OFF=	CARES_BUILD_CONTAINER_TESTS \
		CARES_BUILD_TESTS \
		CARES_COVERAGE \
		CARES_STATIC_PIC \
		CARES_SYMBOL_HIDING \
		CARES_WERROR
CMAKE_ON=	CARES_BUILD_TOOLS \
		CARES_INSTALL \
		CARES_SHARED \
		CARES_THREADS
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	STATIC TEST
OPTIONS_SUB=	yes

STATIC_CMAKE_BOOL=	CARES_STATIC
TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_CMAKE_BOOL=	CARES_BUILD_TESTS
TEST_TEST_TARGET=	test
TEST_USES=		cmake:testing compiler:c++17-lang localbase:ldflags
TEST_USES_OFF=		cmake

.include <bsd.port.mk>
