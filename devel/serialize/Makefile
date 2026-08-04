PORTNAME=	serialize
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	devel

MAINTAINER=	glenn@mas-bandwidth.com
COMMENT=	Header-only bitpacking serializer for C++
WWW=		https://github.com/mas-bandwidth/serialize

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# noninja: the test binary is named "test", which collides with the Ninja
# generator's ctest alias when the test build is enabled
USES=		cmake:testing,noninja
USE_GITHUB=	yes
GH_ACCOUNT=	mas-bandwidth

CMAKE_OFF=	SERIALIZE_BUILD_TESTS
CMAKE_TESTING_ON=	SERIALIZE_BUILD_TESTS

NO_ARCH=	yes

PLIST_FILES=	include/serialize.h \
 		lib/cmake/serialize/serialize-config-version.cmake \
		lib/cmake/serialize/serialize-config.cmake

.include <bsd.port.mk>
