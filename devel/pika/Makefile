PORTNAME=	pika
DISTVERSION=	0.6.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for concurrency and parallelism

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libhwloc.so:devel/hwloc2 \
		libtcmalloc_minimal.so:devel/google-perftools

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pika-org

CMAKE_ON=	PIKA_WITH_MALLOC
CMAKE_TESTING_ON=	PIKA_WITH_TESTS # unclear how to run tests

BINARY_ALIAS=	git=false

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR} # remove copy of license

.include <bsd.port.mk>
