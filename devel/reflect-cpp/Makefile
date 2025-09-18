PORTNAME=	reflect-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	devel

MAINTAINER=	alven@FreeBSD.org
COMMENT=	C++-20 library for fast serialization, deserialization and validation
WWW=		https://rfl.getml.com/ \
		https://github.com/getml/reflect-cpp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++23-lang
USE_GITHUB=	yes
GH_ACCOUNT=	getml

CMAKE_ON=	REFLECTCPP_BUILD_SHARED
CMAKE_TESTING_ON=	REFLECTCPP_BUILD_TESTS

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
