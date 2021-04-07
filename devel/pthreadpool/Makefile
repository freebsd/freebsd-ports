PORTNAME=	pthreadpool
DISTVERSION=	0.1-126
DISTVERSIONSUFFIX=	-gb8374f8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pthread-based thread pool for C/C++ for arrays parallelization

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/fxdiv.h:devel/fxdiv

USES=		cmake compiler:c11 localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Maratyszcza

CMAKE_OFF=	PTHREADPOOL_BUILD_TESTS PTHREADPOOL_BUILD_BENCHMARKS
CMAKE_ON=	BUILD_SHARED_LIBS

PLIST_FILES=	include/pthreadpool.h \
		lib/libpthreadpool.so

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPTHREADPOOL_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
