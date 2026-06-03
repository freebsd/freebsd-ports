PORTNAME=	quill
DISTVERSIONPREFIX=	v
DISTVERSION=	11.1.0
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

CMAKE_TESTING_ON=	QUILL_BUILD_TESTS # 1 tests fails, see https://github.com/odygrd/quill/issues/550

NO_ARCH=	yes

# tests as of 9.0.1: 100% tests passed, 0 tests failed out of 183
# tests as of 11.1.0: 99% tests passed, 2 tests failed out of 259, see https://github.com/odygrd/quill/issues/927

.include <bsd.port.mk>
