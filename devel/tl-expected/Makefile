PORTNAME=		tl-expected
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.1
CATEGORIES=		devel

MAINTAINER=		henry.hu.sh@gmail.com
COMMENT=		C++11/14/17 std::expected with functional-style extensions
WWW=		https://github.com/TartanLlama/expected

LICENSE=		CC0-1.0
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			cmake
USE_GITHUB=		yes
GH_ACCOUNT=		TartanLlama
GH_PROJECT=		expected
NO_ARCH=		yes

OPTIONS_DEFINE=		TESTS
OPTIONS_DEFAULT=

TESTS_DESC=		Build tests
TESTS_CMAKE_BOOL=	EXPECTED_BUILD_TESTS
TESTS_CMAKE_ON=		-DFETCHCONTENT_SOURCE_DIR_CATCH2=${WRKSRC}/catch2

PLIST_FILES=	include/tl/expected.hpp \
		share/cmake/tl-expected/tl-expected-config-version.cmake \
		share/cmake/tl-expected/tl-expected-config.cmake \
		share/cmake/tl-expected/tl-expected-targets.cmake

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
GH_TUPLE=		catchorg:Catch2:v2.13.10:catch2/catch2
.endif

do-test:
.if ${PORT_OPTIONS:MTESTS}
	@${CONFIGURE_WRKSRC}/tl-expected-tests
.else
	@${ECHO} Must build with TESTS on to run tests.
.endif

.include <bsd.port.mk>
