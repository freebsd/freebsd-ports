PORTNAME=	quill
DISTVERSIONPREFIX=	v
DISTVERSION=	8.1.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-logging-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Asynchronous low latency C++ logging library
WWW=		https://github.com/odygrd/quill

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	odygrd

CMAKE_TESTING_ON=	QUILL_BUILD_TESTS # 1 tests fails, see https://github.com/odygrd/quill/issues/550

NO_ARCH=	yes

# tests fail to compile: https://github.com/odygrd/quill/issues/646

.include <bsd.port.mk>
