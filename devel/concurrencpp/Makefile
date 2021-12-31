PORTNAME=	concurrencpp
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.1.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ concurrency library: tasks, executors, timers, C++20 coroutines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_12=	fatal error: 'semaphore' file not found (missing C++ include <semaphore>)

USES=		cmake compiler:c++17-lang # should be compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	David-Haim

CMAKE_ON=	BUILD_SHARED_LIBS

do-test: # same as recommended in https://github.com/David-Haim/concurrencpp#building-installing-and-testing
	@cd ${WRKSRC} && \
		${CMAKE_BIN} -S test -B build/test && \
		${CMAKE_BIN} --build build/test && \
		cd build/test && ctest .

.include <bsd.port.mk>
