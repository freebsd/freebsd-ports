# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlemock
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.10.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Library for writing and using C++ mock classes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtest.so:devel/googletest

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	googletest

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes
CMAKE_ON=	BUILD_GMOCK BUILD_SHARED_LIBS

OPTIONS_DEFINE=	TEST

TEST_USES=		python:build
TEST_CMAKE_BOOL=	gmock_build_tests
TEST_TEST_TARGET=	test

post-install:
# Clean unused stuff: googletest, unprocessed headers
	${FIND} ${STAGEDIR}${PREFIX} \( -ipath "*gtest*" -o \
		-name '*.pump' -o -empty \) -delete

pre-install-TEST-on: do-test

.include <bsd.port.mk>
