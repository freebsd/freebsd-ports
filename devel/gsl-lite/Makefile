PORTNAME=	gsl-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.43.0
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
		lib/cmake/gsl-lite/gsl-lite-config-version.cmake \
		lib/cmake/gsl-lite/gsl-lite-config.cmake \
		lib/cmake/gsl-lite/gsl-lite-targets.cmake

NO_ARCH=	yes

# tests as of 0.43.0: 100% tests passed, 0 tests failed out of 12

.include <bsd.port.mk>
