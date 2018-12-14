# $FreeBSD$

PORTNAME=	ikos
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static analyzer for C/C++ based on theory of abstract interpretation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.pdf

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libapron.so:math/apron \
		libboost_system.so:devel/boost-libs \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libppl.so:devel/ppl

USES=		cmake:outsource ncurses python sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	NASA-SW-VnV

CXXFLAGS+=	-DNDEBUG # https://github.com/NASA-SW-VnV/ikos/issues/36, it also breaks with assert without NDEBUG

CMAKE_ARGS=	-DLLVM_CONFIG_EXECUTABLE:PATH=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT} \
		-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD}

post-configure: # workaround for the problem that --color-diagnostics gets into the linker command lines
	@${REINPLACE_CMD} 's|-Wl,--color-diagnostics| |' ${BUILD_WRKSRC}/build.ninja

# use clang corresponding to the used llvm version
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.include <bsd.port.mk>
