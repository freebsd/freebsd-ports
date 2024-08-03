PORTNAME=	simdjson
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing gigabytes of JSON per second
WWW=		https://simdjson.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang python:test
USE_GITHUB=	yes
USE_LDCONFIG=	yes

# Found in dependencies/CMakeLists.txt
GH_TUPLE=	simdjson:simdjson-data:a5b13ba:simdjson_data/dependencies/.cache/simdjson-data

CMAKE_TESTING_ON=	SIMDJSON_DEVELOPER_MODE
CMAKE_TESTING_OFF=	SIMDJSON_ALLOW_DOWNLOADS \
			SIMDJSON_COMPETITION \
			SIMDJSON_GOOGLE_BENCHMARKS

CMAKE_ON=		BUILD_SHARED_LIBS

CXXFLAGS_i386=		-DSIMDJSON_NO_PORTABILITY_WARNING
CXXFLAGS_powerpc64=	-mpower8-vector

.include <bsd.port.mk>
