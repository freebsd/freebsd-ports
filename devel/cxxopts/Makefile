PORTNAME=	cxxopts
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight C++ command line option parser
WWW=		https://github.com/jarro2783/cxxopts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	jarro2783

CMAKE_OFF=	CXXOPTS_BUILD_TESTS CXXOPTS_BUILD_EXAMPLES
CMAKE_TESTING_ON=	CXXOPTS_BUILD_TESTS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/cxxopts.hpp \
		share/cmake/cxxopts/cxxopts-config-version.cmake \
		share/cmake/cxxopts/cxxopts-config.cmake \
		share/cmake/cxxopts/cxxopts-targets.cmake \
		share/pkgconfig/cxxopts.pc

# tests as of 3.3.1: 100% tests passed, 0 tests failed out of 3

.include <bsd.port.mk>
