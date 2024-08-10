PORTNAME=	quill
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.0
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

CMAKE_TESTING_ON=	QUILL_BUILD_TESTS # 2 tests fail, see https://github.com/odygrd/quill/issues/496

NO_ARCH=	yes

.include <bsd.port.mk>
