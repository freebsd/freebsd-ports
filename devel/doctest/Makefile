PORTNAME=	doctest
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.11
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	Header-only C++ unit-testing
WWW=		https://github.com/onqtam/doctest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	doctest

CMAKE_OFF=	DOCTEST_WITH_TESTS DOCTEST_WITH_MAIN_IN_STATIC_LIB
CMAKE_TESTING_ON=	DOCTEST_WITH_TESTS # tests fail to compile, see https://github.com/doctest/doctest/issues/765

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/doctest/doctest.h \
		include/doctest/extensions/doctest_mpi.h \
		include/doctest/extensions/doctest_util.h \
		include/doctest/extensions/mpi_reporter.h \
		include/doctest/extensions/mpi_sub_comm.h \
		lib/cmake/doctest/doctest.cmake \
		lib/cmake/doctest/doctestAddTests.cmake \
		lib/cmake/doctest/doctestConfig.cmake \
		lib/cmake/doctest/doctestConfigVersion.cmake \
		lib/cmake/doctest/doctestTargets.cmake

.include <bsd.port.mk>
