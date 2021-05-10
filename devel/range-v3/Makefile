PORTNAME=	range-v3
DISTVERSION=	0.11.0
CATEGORIES=	devel

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Experimental range library for C++11/14/17

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	ericniebler

CMAKE_OFF=	RANGE_V3_TESTS RANGE_V3_EXAMPLES

NO_ARCH=	yes

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/module.modulemap

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DRANGE_V3_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

build-examples: build
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DRANGE_V3_EXAMPLES:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}


.include <bsd.port.mk>
