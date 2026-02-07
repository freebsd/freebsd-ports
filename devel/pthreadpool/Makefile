PORTNAME=	pthreadpool
DISTVERSION=	0.1-147
DISTVERSIONSUFFIX=	-g560c60d
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pthread-based thread pool for C/C++ for arrays parallelization
WWW=		https://github.com/Maratyszcza/pthreadpool

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

# 100% tests passed, 0 tests failed out of 2

.include <bsd.port.mk>
