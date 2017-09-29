# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	1.0.4
PORTREVISION=	2
DISTVERSIONPREFIX=	ver.
CATEGORIES=	chinese converters

MAINTAINER=	lichray@gmail.com
COMMENT=	Open Chinese Convert library and utilities

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	BYVoid
GH_PROJECT=	OpenCC

USES=		cmake compiler:c++11-lib python:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TESTS

TESTS_DESC=	Build the unit testing
TESTS_CMAKE_ON=	-DENABLE_GTEST=ON

TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e "s|python|${PYTHON_CMD}|g" \
		${WRKSRC}/data/CMakeLists.txt

.include <bsd.port.mk>
