# $FreeBSD$

PORTNAME=	ikos
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static analyzer for C/C++ based on theory of abstract interpretation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.pdf

BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
LIB_DEPENDS=	libapron.so:math/apron \
		libboost_system.so:devel/boost-libs \
		libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libppl.so:devel/ppl \
		libtbb.so:devel/tbb
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cmake ncurses python:3.6+ sqlite
USE_PYTHON=	py3kplist
USE_GITHUB=	yes
GH_ACCOUNT=	NASA-SW-VnV
USE_LDCONFIG=	yes

LLVM_VERSION=	90 # ${LLVM_DEFAULT} isn't desirable here since ikos only supports llvm>=90, but LLVM_DEFAULT implies that many/any llvm versions are supported

CXXFLAGS+=	-DNDEBUG # https://github.com/NASA-SW-VnV/ikos/issues/36, it also breaks with assert without NDEBUG

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DLLVM_CONFIG_EXECUTABLE:PATH=${LOCALBASE}/bin/llvm-config${LLVM_VERSION} \
		-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD}

post-configure: # workaround for the problem that --color-diagnostics gets into the linker command lines
	@${REINPLACE_CMD} 's|-Wl,--color-diagnostics| |' ${BUILD_WRKSRC}/build.ninja

# use clang corresponding to the used llvm version
CPP=		clang-cpp${LLVM_VERSION}
CC=		clang${LLVM_VERSION}
CXX=		clang++${LLVM_VERSION}

.include <bsd.port.mk>
