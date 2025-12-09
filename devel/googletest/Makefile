PORTNAME=	googletest
PORTVERSION=	1.16.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/google/googletest/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms
WWW=		https://google.github.io/googletest/ \
		https://github.com/google/googletest

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang python:test

CMAKE_OFF=	GTEST_HAS_ABSL \
		gmock_build_tests \
		gtest_build_samples \
		gtest_build_tests \
		gtest_disable_pthreads \
		gtest_hide_internal_symbols
CMAKE_ON=	BUILD_GMOCK \
		BUILD_SHARED_LIBS \
		INSTALL_GTEST
CMAKE_TESTING_ON=	\
		gmock_build_tests \
		gtest_build_tests
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
