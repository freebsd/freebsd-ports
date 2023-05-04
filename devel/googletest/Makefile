PORTNAME=	googletest
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms
WWW=		https://github.com/google/googletest

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake:testing compiler:c++11-lib python:test
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	gtest_build_tests gmock_build_tests

.include <bsd.port.mk>
