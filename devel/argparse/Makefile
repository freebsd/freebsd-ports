PORTNAME=	argparse
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Argument Parser for Modern C++
WWW=		https://github.com/p-ranav/argparse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	p-ranav

NO_ARCH=	yes

PLIST_FILES=	include/argparse/argparse.hpp \
		lib/cmake/argparse/argparseConfig-version.cmake \
		lib/cmake/argparse/argparseConfig.cmake \
		libdata/pkgconfig/argparse.pc

OPTIONS_DEFINE=		TEST
TEST_CMAKE_BOOL=	ARGPARSE_BUILD_TESTS

test:
		@if [ -x ${WRKDIR}/.build/test/tests ]; then \
			${WRKDIR}/.build/test/tests; \
		fi

.include <bsd.port.mk>
