# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	googletest
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.11.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake:testing compiler:c++11-lib python:test
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	gtest_build_tests gmock_build_tests

.include <bsd.port.mk>
