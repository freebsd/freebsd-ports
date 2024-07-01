PORTNAME=	zlib-ng
DISTVERSION=	2.1.7
CATEGORIES=	archivers

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Fork of the zlib data compression library
WWW=		https://github.com/zlib-ng/zlib-ng

LICENSE=	ZLIB

USES=		cmake:${TESTING} compiler:c11
USE_GITHUB=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=	SIMD TEST

SIMD_CMAKE_BOOL=	WITH_OPTIM
TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_CMAKE_BOOL=	ZLIB_ENABLE_TESTS ZLIBNG_ENABLE_TESTS
# error: use of undeclared identifier 'isascii'
TEST_CFLAGS=		-D__XSI_VISIBLE
TEST_VARS=		TESTING=testing

.include <bsd.port.mk>
