PORTNAME=	flatbuffers
DISTVERSIONPREFIX=	v
DISTVERSION=	25.9.23
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Memory efficient serialization library
WWW=		https://flatbuffers.dev/ \
		https://github.com/google/flatbuffers

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++14-lang cpe python:build
CPE_VENDOR=	google
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	FLATBUFFERS_BUILD_SHAREDLIB
CMAKE_OFF=	FLATBUFFERS_BUILD_FLATLIB FLATBUFFERS_BUILD_TESTS
CMAKE_TESTING_ON=	FLATBUFFERS_BUILD_TESTS # one test fails, see https://github.com/google/flatbuffers/issues/7009 and https://github.com/google/flatbuffers/issues/7556

BINARY_ALIAS=	git=false python3=${PYTHON_CMD}

# 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
