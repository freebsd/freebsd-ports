PORTNAME=	flatbuffers
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
CATEGORIES=	devel
PKGNAMESUFFIX=	205

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Memory efficient serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++11-lib cpe python:build
CPE_VENDOR=	google
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	FLATBUFFERS_BUILD_SHAREDLIB
CMAKE_OFF=	FLATBUFFERS_BUILD_FLATLIB FLATBUFFERS_BUILD_TESTS
CMAKE_TESTING_ON=	FLATBUFFERS_BUILD_TESTS # one test fails, see https://github.com/google/flatbuffers/issues/7009

BINARY_ALIAS=	git=false python3=${PYTHON_CMD}

.include <bsd.port.mk>
