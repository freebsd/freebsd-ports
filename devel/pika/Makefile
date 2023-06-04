PORTNAME=	pika
DISTVERSION=	0.16.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for concurrency and parallelism
WWW=		https://github.com/pika-org/pika

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_FreeBSD_12=	compilation error: /usr/include/sys/sysctl.h:1117:25: error: unknown type name 'u_int'
BROKEN_aarch64=		compilation error: error: 'regparm' is not valid on this platform

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libhwloc.so:devel/hwloc2 \
		libtcmalloc_minimal.so:devel/google-perftools

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pika-org

CMAKE_ON=	PIKA_WITH_MALLOC
CMAKE_ON+=	PIKA_WITH_GENERIC_CONTEXT_COROUTINES # prerequisite, build breaks on aarch64, armv6 w/out it
CMAKE_TESTING_ON=	PIKA_WITH_TESTS PIKA_WITH_TESTS_UNIT
CMAKE_TESTING_TARGET=	tests

BINARY_ALIAS=	git=false

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR} # remove copy of license

pre-test: # unlike most other cmake projects tests fail to build when reconfigured, and require full rebuild
	@${RM} -r ${BUILD_WRKSRC}/*

.include <bsd.port.mk>
