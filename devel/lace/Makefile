PORTNAME=	lace
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-work-stealing

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of work-stealing in C
WWW=		https://github.com/trolando/lace

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error: static assertion failed due to requirement '(sizeof(struct _lace_task) % 64) == 0': lace_task size should be a multiple of LACE_CACHE_LINE_SIZE
BROKEN_i386=	compilation fails: error: static assertion failed due to requirement '(sizeof(struct _lace_task) % 64) == 0': lace_task size should be a multiple of LACE_CACHE_LINE_SIZE

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	trolando

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		LACE_BUILD_TESTS
CMAKE_TESTING_ON=	LACE_BUILD_TESTS

PORTSCOUT=	limit:^.*[0-9]+\.[0-9]+\.[0-9]+$$ # prevent tags like mucocos_2014_ri

pre-configure: # see discussion in https://github.com/trolando/lace/issues/16
	@${REINPLACE_CMD} -e 's,memory_order_[[:alnum:]_]*,memory_order_seq_cst,g' \
		${WRKSRC}/src/*.[ch] ${WRKSRC}/src/lace.sh

# tests as of 2.0.2: 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
