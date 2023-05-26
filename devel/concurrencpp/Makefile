PORTNAME=	concurrencpp
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.1.6
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ concurrency library: tasks, executors, timers, C++20 coroutines
WWW=		https://github.com/David-Haim/concurrencpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	David-Haim

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le || ${ARCH} == powerpc64 || ${ARCH} == powerpc
CXX=		clang++${LLVM_VERSION}
USES+=		llvm:min=16
.endif

do-test: # same as recommended in https://github.com/David-Haim/concurrencpp#building-installing-and-testing
	@cd ${WRKSRC} && \
		${CMAKE_BIN} -S test -B build/test && \
		${CMAKE_BIN} --build build/test && \
		cd build/test && ctest .

.include <bsd.port.mk>
