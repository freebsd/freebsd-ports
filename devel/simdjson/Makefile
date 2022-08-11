PORTNAME=	simdjson
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	devel

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing gigabytes of JSON per second

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	does not build (error: unknown type name '__uint128_t')
CXXFLAGS_powerpc64=	-mpower8-vector

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_TESTING_TARGET=	all_tests

CMAKE_ON=	SIMDJSON_JUST_LIBRARY \
		BUILD_SHARED_LIBS

.include <bsd.port.mk>
