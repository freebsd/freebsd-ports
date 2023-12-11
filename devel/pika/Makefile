PORTNAME=	pika
DISTVERSION=	0.21.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for concurrency and parallelism
WWW=		https://github.com/pika-org/pika

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BROKEN_FreeBSD_12=	compilation error: /usr/include/sys/sysctl.h:1117:25: error: unknown type name 'u_int'
BROKEN_aarch64=		compilation error: error: 'regparm' is not valid on this platform

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhwloc.so:devel/hwloc2

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pika-org

CMAKE_ON=	PIKA_WITH_MALLOC
CMAKE_ON+=	PIKA_WITH_GENERIC_CONTEXT_COROUTINES # prerequisite, build breaks on aarch64, armv6 w/out it
CMAKE_TESTING_ON=	PIKA_WITH_TESTS PIKA_WITH_TESTS_UNIT PIKA_WITH_TESTS_REGRESSIONS # see https://pikacpp.org/usage.html#testing
CMAKE_TESTING_TARGET=	tests # first build the tests, according to https://pikacpp.org/usage.html#testing

BINARY_ALIAS=	git=false

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR} # remove copy of license

post-test: # run the tests according to https://pikacpp.org/usage.html#testing (make tests test doesn't work)
	# some tests fail, see https://github.com/pika-org/pika/issues/895
	@cd ${BUILD_WRKSRC} && \
		${MAKE_CMD} test

.include <bsd.port.mk>
