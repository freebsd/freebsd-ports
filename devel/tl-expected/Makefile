# $FreeBSD$

PORTNAME=		tl-expected
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.0
CATEGORIES=		devel

MAINTAINER=		henry.hu.sh@gmail.com
COMMENT=		C++11/14/17 std::expected with functional-style extensions

LICENSE=		PD
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			cmake
USE_GITHUB=		yes
GH_ACCOUNT=		TartanLlama
GH_PROJECT=		expected
GH_TUPLE=		TartanLlama:tl-cmake:284c6a3:tlcmake/cmake/tl-cmake
NO_ARCH=		yes
CMAKE_ARGS=		-DFETCHCONTENT_SOURCE_DIR_TL_CMAKE=${CMAKE_SOURCE_PATH}/cmake/tl-cmake

OPTIONS_DEFINE=		TESTS
OPTIONS_DEFAULT=

TESTS_DESC=		Build tests
TESTS_CMAKE_BOOL=	EXPECTED_ENABLE_TESTS

.include <bsd.port.options.mk>

do-test:
.if ${PORT_OPTIONS:MTESTS}
	@${CONFIGURE_WRKSRC}/tests
.else
	@${ECHO} Must build with TESTS on to run tests.
.endif

.include <bsd.port.mk>
