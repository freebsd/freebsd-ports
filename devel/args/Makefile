PORTNAME=	args
DISTVERSION=	6.4.16
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only C++ argument parser library
WWW=		https://github.com/Taywee/args

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	Taywee

CMAKE_OFF=	ARGS_BUILD_EXAMPLE ARGS_BUILD_UNITTESTS
CMAKE_TESTING_ON=	ARGS_BUILD_UNITTESTS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/args.hxx \
		share/cmake/args/args-config.cmake \
		share/cmake/args/args-config-version.cmake \
		share/pkgconfig/args.pc

# tests as of 6.4.16: 100% tests passed, 0 tests failed out of 69

.include <bsd.port.mk>
