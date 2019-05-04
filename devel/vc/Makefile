# $FreeBSD$

PORTNAME=	vc
DISTVERSION=	1.4.1-10
DISTVERSIONSUFFIX=	-g383ef32b
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SIMD Vector Classes for C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	VcDevel
GH_PROJECT=	Vc
GH_TUPLE=	VcDevel:vc-testdata:9ada1f3:testdata/tests/testdata \
		mattkretz:virtest:f7d03ef:virtest/tests/virtest

CMAKE_OFF=	BUILD_TESTING

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
