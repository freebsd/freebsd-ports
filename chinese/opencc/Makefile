PORTNAME=	opencc
DISTVERSIONPREFIX=	ver.
DISTVERSION=	1.3.1
CATEGORIES=	chinese converters

MAINTAINER=	lichray@gmail.com
COMMENT=	Open Chinese Convert library and utilities
WWW=		https://github.com/BYVoid/OpenCC

LICENSE=	APACHE20

USES=		cmake:testing compiler:c++11-lib python:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	BYVoid
GH_PROJECT=	OpenCC

CMAKE_TESTING_ON=	ENABLE_GTEST

TEST_TARGET=	test

# tests as of 1.3.1: 100% tests passed, 0 tests failed out of 18

.include <bsd.port.mk>
