PORTNAME=	simdjson
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	devel

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing gigabytes of JSON per second
WWW=		https://simdjson.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	does not build (error: unknown type name '__uint128_t')
CXXFLAGS_powerpc64=	-mpower8-vector

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	SIMDJSON_DEVELOPER_MODE
CMAKE_TESTING_OFF=	SIMDJSON_JUST_LIBRARY

CMAKE_ON=	SIMDJSON_JUST_LIBRARY \
		BUILD_SHARED_LIBS

.include <bsd.port.mk>
