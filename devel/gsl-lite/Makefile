PORTNAME=	gsl-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the C++ Core Guidelines Support Library
WWW=		https://github.com/gsl-lite/gsl-lite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_GITHUB=	yes

CMAKE_TESTING_ON=	GSL_LITE_OPT_BUILD_TESTS

PLIST_FILES=	include/gsl-lite/gsl-lite.hpp \
		include/gsl/gsl-lite.hpp \
		share/cmake/gsl-lite/gsl-liteConfig.cmake \
		share/cmake/gsl-lite/gsl-liteConfigVersion.cmake \
		share/cmake/gsl-lite/gsl-liteTargets.cmake

NO_ARCH=	yes

# tests as of 1.1.0: 100% tests passed, 0 tests failed out of 15

.include <bsd.port.mk>
