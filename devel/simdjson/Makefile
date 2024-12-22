PORTNAME=	simdjson
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.3
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parsing gigabytes of JSON per second
WWW=		https://simdjson.org/ \
		https://github.com/simdjson/simdjson/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang python:test
USE_GITHUB=	yes
# Found in dependencies/CMakeLists.txt
GH_TUPLE=	simdjson:simdjson-data:a5b13ba:simdjson_data/dependencies/.cache/simdjson-data
USE_LDCONFIG=	yes

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	SIMDJSON_DEVELOPER_MODE
CMAKE_TESTING_OFF=	SIMDJSON_ALLOW_DOWNLOADS \
			SIMDJSON_COMPETITION \
			SIMDJSON_GOOGLE_BENCHMARKS

CXXFLAGS_i386=		-DSIMDJSON_NO_PORTABILITY_WARNING
CXXFLAGS_powerpc64=	-mpower8-vector

.include <bsd.port.mk>
