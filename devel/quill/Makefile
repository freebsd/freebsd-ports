PORTNAME=	quill
DISTVERSIONPREFIX=	v
DISTVERSION=	13.0.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-logging-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous low latency C++ logging library
WWW=		https://github.com/odygrd/quill

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	odygrd

CMAKE_TESTING_ON=	QUILL_BUILD_TESTS

NO_ARCH=	yes

# tests as of 13.0.0: 100% tests passed, 0 tests failed out of 419

.include <bsd.port.mk>
