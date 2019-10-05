# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googletest
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.10.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for writing C++ tests on a variety of platforms

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_GMOCK

OPTIONS_DEFINE=	TEST

TEST_USES=		python:build
TEST_CMAKE_BOOL=	gtest_build_tests
TEST_TEST_TARGET=	test

pre-install-TEST-on: do-test

.include <bsd.port.mk>
