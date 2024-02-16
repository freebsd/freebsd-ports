PORTNAME=	zlib-ng
DISTVERSION=	2.1.6
CATEGORIES=	archivers

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Fork of the zlib data compression library
WWW=		https://github.com/zlib-ng/zlib-ng

LICENSE=	ZLIB

USES=		cmake compiler:c11
USE_LDCONFIG=	yes
USE_GITHUB=	yes

OPTIONS_DEFINE=	SIMD TEST

SIMD_CMAKE_BOOL=	WITH_OPTIM
TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_CMAKE_BOOL=	ZLIB_ENABLE_TESTS ZLIBNG_ENABLE_TESTS
TEST_BROKEN=		error: use of undeclared identifier 'isascii'

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
