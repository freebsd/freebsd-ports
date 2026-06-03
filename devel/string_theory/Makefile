PORTNAME=	string_theory
PORTVERSION=	3.9
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern C++ library for string manipulation and storage
WWW=		https://github.com/zrax/string_theory

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++20-lang localbase:ldflags

CMAKE_OFF=	ST_BUILD_TEST_COVERAGE \
		ST_BUILD_TESTS
CMAKE_ON=	ST_ENABLE_STL_FILESYSTEM \
		ST_ENABLE_STL_STRINGS
CMAKE_TESTING_OFF=	\
		BUILD_GMOCK \
		INSTALL_GTEST \
		ST_BUILD_PROFILE_TEST
CMAKE_TESTING_ON=	\
		ST_BUILD_TEST_COVERAGE \
		ST_BUILD_TESTS \
		ST_USE_SYSTEM_GTEST
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	zrax

.include <bsd.port.mk>
