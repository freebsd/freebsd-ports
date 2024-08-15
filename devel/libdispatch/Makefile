PORTNAME=	libdispatch
DISTVERSION=	5.10.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Grand Central Dispatch API support library

LICENSE=	APACHE20

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	swift-corelibs-libdispatch
GH_TAGNAME=	swift-${DISTVERSION}-RELEASE

.include <bsd.port.options.mk>

#.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400000 && ${OSVERSION} < 1400079
#USES+=	llvm:max=17,build
#USES:=	${USES:Ncompiler\:*} # XXX avoid warnings
#CC=	${_LLVM_MK_PREFIX}/bin/clang
#CPP=	${_LLVM_MK_PREFIX}/bin/clang-cpp
#CXX=	${_LLVM_MK_PREFIX}/bin/clang++
#LD?=	${_LLVM_MK_PREFIX}/bin/ld
#.endif

.if ${OPSYS} == FreeBSD && ${ARCH} == i386
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
