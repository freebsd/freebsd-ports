# $FreeBSD$

PORTNAME=	doctest
DISTVERSION=	2.3.8
CATEGORIES=	devel

MAINTAINER=	nickblack@linux.com
COMMENT=	Header-only C++ unit-testing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++17-lang cmake
USE_GITHUB=	yes
GH_ACCOUNT=	onqtam

NO_BUILD=	yes
NO_ARCH=	yes

CMAKE_OFF=	DOCTEST_WITH_TESTS DOCTEST_WITH_MAIN_IN_STATIC_LIB

PLIST_FILES=	include/doctest/doctest.h \
		lib/cmake/doctest/doctest.cmake \
		lib/cmake/doctest/doctestAddTests.cmake \
		lib/cmake/doctest/doctestConfig.cmake \
		lib/cmake/doctest/doctestConfigVersion.cmake \
		lib/cmake/doctest/doctestTargets.cmake

.include <bsd.port.mk>
