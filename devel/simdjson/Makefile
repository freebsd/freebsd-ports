PORTNAME=	simdjson
DISTVERSIONPREFIX=	v
PORTVERSION=	4.0.6
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Parsing gigabytes of JSON per second
WWW=		https://simdjson.org/ \
		https://github.com/simdjson/simdjson/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cmake:testing compiler:c++17-lang pathfix python:test
USE_GITHUB=	yes
# Found in dependencies/CMakeLists.txt
GH_TUPLE=	simdjson:simdjson-data:351949906abde446f0314bf79606fb5d884f5be7:simdjson_data/dependencies/.cache/simdjson-data
USE_LDCONFIG=	yes

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	SIMDJSON_DEVELOPER_MODE
CMAKE_TESTING_OFF=	SIMDJSON_ALLOW_DOWNLOADS \
			SIMDJSON_COMPETITION \
			SIMDJSON_GOOGLE_BENCHMARKS

CXXFLAGS_i386=		-DSIMDJSON_NO_PORTABILITY_WARNING
CXXFLAGS_powerpc64=	-mpower8-vector

.include <bsd.port.mk>
