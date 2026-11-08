PORTNAME=	perftest
DISTVERSIONPREFIX=	v
DISTVERSION=    4.5-0.17
CATEGORIES=	benchmarks
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of tests for RDMA micro-benchmark
WWW=		https://github.com/linux-rdma/perftest/

LICENSE=	LGPL21 BSD2CLAUSE
LICENSE_COMB=	dual

FLAVORS=	base_ofed rdma_core
FLAVOR?=	${FLAVORS:[1]}

USES=		autoreconf libtool shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	linux-rdma

SHEBANG_FILES=	run_perftest_multi_devices

GNU_CONFIGURE=yes

.if ${FLAVOR} == rdma_core
USES+=		localbase:ldflags

LIB_DEPENDS+=	libibverbs.so.100:net/rdma-core

# transitive dep of rdma-core
CFLAGS+=	-I${LOCALBASE}/include/linuxapi
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib
.endif

.include <bsd.port.mk>
