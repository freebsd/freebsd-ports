# $FreeBSD$

PORTNAME=	benchmark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1-25
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gaf441fc
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Microbenchmark support library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	google
USE_LDCONFIG=	yes

CMAKE_OFF=	BENCHMARK_ENABLE_TESTING

CXXFLAGS+=	-Wno-thread-safety-analysis # workaround for https://github.com/google/benchmark/issues/655
CXXFLAGS+=	-Wno-sign-compare # workaround for https://github.com/google/googletest/issues/1752

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBENCHMARK_ENABLE_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
